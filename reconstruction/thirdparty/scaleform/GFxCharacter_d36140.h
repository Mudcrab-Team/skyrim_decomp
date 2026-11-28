// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// GFxCharacter, GFxCharacter::IsVerboseActionErrors: CRASHLOGGER_PDB(59818@2026.10.24)
// GFxCharacterWeakBase, GFxLogBase, GFxMovieRoot, GetMovieRoot, flags: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct GFxMovieRoot
{
    std::uint8_t unk00[0x25E0];  // 00
    std::uint32_t flags;  // 25E0
};
static_assert(offsetof(GFxMovieRoot, flags) == 0x25E0, "flags offset");

class GFxCharacterWeakBase
{
public:
    virtual ~GFxCharacterWeakBase();  // 00

    std::uint64_t unk08[2];  // 08
};
static_assert(sizeof(GFxCharacterWeakBase) == 0x18, "GFxCharacterWeakBase size");

class GFxLogBase
{
public:
    virtual ~GFxLogBase();  // 00
    virtual bool IsVerboseActionErrors() const;  // 01
};
static_assert(sizeof(GFxLogBase) == 0x08, "GFxLogBase size");

class GFxCharacter :
    public GFxCharacterWeakBase,
    public GFxLogBase
{
public:
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual GFxMovieRoot* GetMovieRoot() const;  // 15 (0xA8)

    bool IsVerboseActionErrors() const override;  // compared: 0xd36140
};
