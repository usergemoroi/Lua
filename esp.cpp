#include "esp.h"
#include "../memory/memory.h"
#include "../sdk/offsets.h"
#include "../sdk/game/game.h"
#include "../sdk/player/player.h"
#include "../network/socket_server.h"
#include <cmath>
#include <cstring>
#include <unordered_map>

static uint8_t g_binary_buffer[16384];

struct PlayerCache {
    std::string name;
    int name_frame = 0;
};

static std::unordered_map<uint32_t, PlayerCache> g_player_cache;
static int g_frame_counter = 0;

ESP::ESP(uint32_t libunity_base) : libunity_base_(libunity_base) {}

void ESP::Render() {
    g_frame_counter++;
    
    Game game(libunity_base_);
    
    if (!game.IsValid()) {
        uint8_t empty[4] = {0, 0, 0, 0};
        g_socket_server.set_player_data(empty, 4);
        return;
    }

    Matrix viewMatrix;
    if (!game.ReadViewMatrix(viewMatrix)) {
        uint8_t empty[4] = {0, 0, 0, 0};
        g_socket_server.set_player_data(empty, 4);
        return;
    }

    Vec3 localPos = game.GetLocalPosition();
    uint8_t localTeam = game.GetLocalTeam();

    std::vector<Player> players = game.GetPlayers();

    uint8_t* writer = g_binary_buffer;
    *writer++ = 1;
    *writer++ = 0;
    uint8_t* playerCountPos = writer;
    *writer++ = 0;
    *writer++ = 0;

    memcpy(writer, &viewMatrix.m[0][0], 64);
    writer += 64;

    uint16_t screenW = 1920;
    uint16_t screenH = 1080;
    memcpy(writer, &screenW, 2); writer += 2;
    memcpy(writer, &screenH, 2); writer += 2;

    memcpy(writer, &localPos.x, 4); writer += 4;
    memcpy(writer, &localPos.y, 4); writer += 4;
    memcpy(writer, &localPos.z, 4); writer += 4;
    *writer++ = localTeam;
    *writer++ = 0;
    *writer++ = 0;
    *writer++ = 0;

    uint16_t validPlayers = 0;

    for (const Player& player : players) {
        if (!player.IsValid()) continue;

        Vec3 pos = player.GetPosition();
        if (pos.x == 0 && pos.y == 0 && pos.z == 0) continue;

        uint8_t team = player.GetTeam();
        if (team == localTeam) continue;

        Vec3 head = pos + Vec3(0, 1.7f, 0);

        memcpy(writer, &pos.x, 4); writer += 4;
        memcpy(writer, &pos.y, 4); writer += 4;
        memcpy(writer, &pos.z, 4); writer += 4;
        memcpy(writer, &head.x, 4); writer += 4;
        memcpy(writer, &head.y, 4); writer += 4;
        memcpy(writer, &head.z, 4); writer += 4;
        *writer++ = team;

        uint8_t health = (uint8_t)player.GetHealth();
        uint8_t armor = (uint8_t)player.GetArmor();
        *writer++ = health;
        *writer++ = armor;

        uint8_t flags = 0x01;
        *writer++ = flags;

        *writer++ = 0;
        *writer++ = 0;
        *writer++ = 0;
        *writer++ = 0;

        PlayerCache& cache = g_player_cache[player.GetBase()];
        if (cache.name.empty() || (g_frame_counter - cache.name_frame) > 600) {
            cache.name = player.GetName();
            cache.name_frame = g_frame_counter;
        }

        uint8_t nameLen = (uint8_t)(cache.name.length() > 255 ? 255 : cache.name.length());
        *writer++ = nameLen;
        memcpy(writer, cache.name.c_str(), nameLen);
        writer += nameLen;

        validPlayers++;
    }

    memcpy(playerCountPos, &validPlayers, 2);

    size_t totalSize = writer - g_binary_buffer;
    g_socket_server.set_player_data(g_binary_buffer, totalSize);

    if (g_frame_counter % 5000 == 0) {
        g_player_cache.clear();
    }
}
