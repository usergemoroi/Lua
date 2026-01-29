#include "player.h"
#include "../../memory/memory.h"
#include "../offsets.h"
#include <cmath>

static std::string ReadString(uint32_t strPtr) {
    if (!strPtr || strPtr < 0x10000) return "";
    
    int len = c_memory_utils.read<int>(strPtr + 0x08);
    if (len <= 0 || len > 32) return "";
    
    char16_t buf[64] = {0};
    memory_utils::read_memory((void*)(uintptr_t)(strPtr + 0x0C), buf, len * 2);
    
    std::string result;
    for (int i = 0; i < len && buf[i]; i++) {
        char16_t c = buf[i];
        if (c < 0x80) {
            result += (char)c;
        } else if (c < 0x800) {
            result += (char)(0xC0 | (c >> 6));
            result += (char)(0x80 | (c & 0x3F));
        } else {
            result += (char)(0xE0 | (c >> 12));
            result += (char)(0x80 | ((c >> 6) & 0x3F));
            result += (char)(0x80 | (c & 0x3F));
        }
    }
    return result;
}

Player::Player(uint32_t base) : base_(base) {}

Vec3 Player::GetPosition() const {
    if (!base_ || base_ < 0x10000) return Vec3();

    uint32_t movement = c_memory_utils.read<uint32_t>(base_ + off::movement_controller);
    if (!movement || movement < 0x10000) return Vec3();

    uint32_t snapshot = c_memory_utils.read<uint32_t>(movement + off::snapshot);
    if (!snapshot || snapshot < 0x10000) return Vec3();

    float pos[3];
    if (!memory_utils::read_memory((void*)(uintptr_t)(snapshot + off::snapshot_pos), pos, 12)) return Vec3();

    Vec3 result(pos[0], pos[1], pos[2]);
    if (std::isnan(result.x)) return Vec3();
    return result;
}

std::string Player::GetName() const {
    if (!base_ || base_ < 0x10000) return "";

    uint32_t photon = c_memory_utils.read<uint32_t>(base_ + off::photon_player);
    if (!photon || photon < 0x10000) return "";

    uint32_t namePtr = c_memory_utils.read<uint32_t>(photon + off::photon_name);
    if (!namePtr || namePtr < 0x10000) return "";

    return ReadString(namePtr);
}

int Player::GetPhotonProperty(const char* keyName) const {
    if (!base_ || base_ < 0x10000) return -1;

    uint32_t photon = c_memory_utils.read<uint32_t>(base_ + off::photon_player);
    if (!photon || photon < 0x10000) return -1;

    uint32_t dict = c_memory_utils.read<uint32_t>(photon + off::custom_properties);
    if (!dict || dict < 0x10000) return -1;

    int count = c_memory_utils.read<int>(dict + off::props_count);
    if (count <= 0 || count > 100) return -1;

    uint32_t entries_arr = c_memory_utils.read<uint32_t>(dict + off::props_entries);
    if (!entries_arr || entries_arr < 0x10000) return -1;

    for (int i = 0; i < count && i < 50; i++) {
        uint32_t entryBase = entries_arr + 0x10 + i * 0x10;

        uint32_t keyPtr = c_memory_utils.read<uint32_t>(entryBase + 0x8);
        uint32_t valuePtr = c_memory_utils.read<uint32_t>(entryBase + 0xC);

        if (!keyPtr || keyPtr < 0x10000) continue;
        if (!valuePtr || valuePtr < 0x10000) continue;

        std::string key = ReadString(keyPtr);

        if (key.find(keyName) != std::string::npos) {
            int val = c_memory_utils.read<int>(valuePtr + off::boxed_value);
            return val;
        }
    }

    return -1;
}

int Player::GetHealth() const {
    int hp = GetPhotonProperty("health");
    return (hp > 0 && hp <= 100) ? hp : 100;
}

int Player::GetArmor() const {
    int ar = GetPhotonProperty("armor");
    return ar >= 0 ? ar : 0;
}

uint8_t Player::GetTeam() const {
    return c_memory_utils.read<uint8_t>(base_ + off::team);
}
