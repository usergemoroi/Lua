#pragma once
#include "../player/player.h"
#include "../../types.h"
#include <cstdint>
#include <vector>

class Game {
public:
    Game(uint32_t libunity_base);
    
    bool IsValid() const;
    Player GetLocalPlayer() const;
    std::vector<Player> GetPlayers() const;
    bool ReadViewMatrix(Matrix& vm) const;
    Vec3 GetLocalPosition() const;
    uint8_t GetLocalTeam() const;
    
private:
    uint32_t libunity_base_;
    uint32_t GetPlayerManager() const;
    uint32_t GetInstance(uint32_t typeInfoOffset) const;
};
