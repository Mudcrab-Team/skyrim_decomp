// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// UnregisterFactory2f83d0, Obj2f83d0Base, Obj2f83d0: GUESS(low)
#pragma once

#include <cstdint>

void UnregisterFactory2f83d0(std::uint8_t a_formType);

class Obj2f83d0Base
{
public:
    virtual ~Obj2f83d0Base() {}
};

class Obj2f83d0 : public Obj2f83d0Base
{
public:
    ~Obj2f83d0() override;
};
