#pragma once
#include "../../types.h"
#include <cstdint>
#include <string>

class Player {
public:
    Player(uint32_t base);
    
    bool IsValid() const { return base_ != 0; }
    uint32_t GetBase() const { return base_; }
    
    Vec3 GetPosition() const;
    std::string GetName() const;
    int GetHealth() const;
    int GetArmor() const;
    uint8_t GetTeam() const;
    
private:
    uint32_t base_;
    int GetPhotonProperty(const char* keyName) const;
};
