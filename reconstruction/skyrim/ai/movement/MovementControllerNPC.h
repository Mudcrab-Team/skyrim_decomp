// Source exposure: mixed (local binary analysis and pinned community declarations).
// Code origin: original reconstruction from the pinned image and community declarations.
// Consulted (private, not in repo): decompiler control-flow hints.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MovementControllerNPC, Unk_01, Unk_02, Unk_03, Unk_04, Unk_05, Unk_06, Unk_07, Unk_08, Unk_09, Unk_0A, Unk_0B, Unk_0C, Unk_0D, Unk_0E, Unk_0F, unk1C5: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG names the member unk1C5 and the slots as declared here
// unknown08 to unknown1C8: GUESS(low); the members of NG's class and its bases as unresolved words at their offsets (NG: unk00C to unk1C8)
#pragma once

#include <cstddef>
#include <cstdint>

class MovementControllerNPC {
public:
    virtual ~MovementControllerNPC();  // 00
    virtual void Unk_01();             // 01
    virtual void Unk_02();             // 02
    virtual void Unk_03();             // 03
    virtual void Unk_04();             // 04
    virtual void Unk_05();             // 05
    virtual void Unk_06();             // 06
    virtual void Unk_07();             // 07
    virtual void Unk_08();             // 08
    virtual void Unk_09();             // 09
    virtual void Unk_0A();             // 0A
    virtual void Unk_0B();             // 0B
    virtual void Unk_0C();             // 0C
    virtual void Unk_0D();             // 0D
    virtual void Unk_0E();             // 0E
    virtual std::uint8_t Unk_0F();     // 0F; compared: 0x796ac0

    std::uint32_t unknown08;  // 08
    std::uint32_t unknown0C;  // 0C
    std::uint64_t unknown010;  // 010
    std::uint64_t unknown018;  // 018
    std::uint64_t unknown020;  // 020
    std::uint64_t unknown028;  // 028
    std::uint64_t unknown030;  // 030
    std::uint64_t unknown038;  // 038
    std::uint64_t unknown040;  // 040
    std::uint64_t unknown048;  // 048
    std::uint64_t unknown050;  // 050
    std::uint64_t unknown058;  // 058
    std::uint64_t unknown060;  // 060
    std::uint64_t unknown068;  // 068
    std::uint64_t unknown070;  // 070
    std::uint64_t unknown078;  // 078
    std::uint64_t unknown080;  // 080
    std::uint64_t unknown088;  // 088
    std::uint64_t unknown090;  // 090
    std::uint64_t unknown098;  // 098
    std::uint64_t unknown0A0;  // 0A0
    std::uint64_t unknown0A8;  // 0A8
    std::uint64_t unknown0B0;  // 0B0
    std::uint64_t unknown0B8;  // 0B8
    std::uint64_t unknown0C0;  // 0C0
    std::uint64_t unknown0C8;  // 0C8
    std::uint64_t unknown0D0;  // 0D0
    std::uint64_t unknown0D8;  // 0D8
    std::uint64_t unknown0E0;  // 0E0
    std::uint64_t unknown0E8;  // 0E8
    std::uint64_t unknown0F0;  // 0F0
    std::uint64_t unknown0F8;  // 0F8
    std::uint64_t unknown100;  // 100
    std::uint64_t unknown108;  // 108
    std::uint64_t unknown110;  // 110
    std::uint64_t unknown118;  // 118
    std::uint64_t unknown120;  // 120
    std::uint64_t unknown128;  // 128
    std::uint64_t unknown130;  // 130
    std::uint64_t unknown138;  // 138
    std::uint64_t unknown140;  // 140
    std::uint64_t unknown148;  // 148
    std::uint64_t unknown150;  // 150
    std::uint64_t unknown158;  // 158
    std::uint64_t unknown160;  // 160
    std::uint64_t unknown168;  // 168
    std::uint64_t unknown170;  // 170
    std::uint64_t unknown178;  // 178
    std::uint64_t unknown180;  // 180
    std::uint64_t unknown188;  // 188
    std::uint64_t unknown190;  // 190
    std::uint64_t unknown198;  // 198
    std::uint64_t unknown1A0;  // 1A0
    std::uint64_t unknown1A8;  // 1A8
    std::uint64_t unknown1B0;  // 1B0
    std::uint64_t unknown1B8;  // 1B8
    std::uint32_t unknown1C0;  // 1C0
    std::uint8_t  unknown1C4;  // 1C4
    std::uint8_t  unknown1C5;  // 1C5
    std::uint16_t unknown1C6;  // 1C6
    std::uint64_t unknown1C8;  // 1C8
};
static_assert(sizeof(MovementControllerNPC) == 0x1D0, "MovementControllerNPC size");
static_assert(offsetof(MovementControllerNPC, unknown1C5) == 0x1C5, "MovementControllerNPC::unk1C5 offset");
