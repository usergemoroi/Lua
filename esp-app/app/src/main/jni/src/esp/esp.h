#pragma once
#include "../types.h"
#include <cstdint>

class ESP {
public:
    ESP(uint32_t libunity_base);
    void Render();
    
private:
    uint32_t libunity_base_;
};
