// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Obj299c40, Obj299c40::Function299c40: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Obj299c40
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void AddChange(std::uint32_t a_flag);

    void Function299c40(bool a_cleared);

    std::uint8_t unk08[0xE4];  // 0x08
    bool cleared;              // 0xEC
    bool everCleared;          // 0xED
};

static_assert(offsetof(Obj299c40, cleared) == 0xEC, "cleared offset");
static_assert(offsetof(Obj299c40, everCleared) == 0xED, "everCleared offset");
