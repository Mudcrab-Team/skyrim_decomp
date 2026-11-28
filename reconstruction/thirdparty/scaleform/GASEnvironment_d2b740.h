// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// GASEnvironment, IsVerboseActionErrors: CRASHLOGGER_PDB(59818@2026.10.24)
// GFxMovieRoot, GFxASCharacter: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// GetMovieRoot, target, flags25E0, unk00, Unk_01..Unk_14: GUESS(low)
#pragma once

#include <cstdint>

struct GFxMovieRoot
{
    std::uint8_t  unk00[0x25E0];  // 0000
    std::uint32_t flags25E0;      // 25E0
};

class GFxASCharacter
{
public:
    virtual ~GFxASCharacter();
    virtual void Unk_01(); virtual void Unk_02(); virtual void Unk_03(); virtual void Unk_04();
    virtual void Unk_05(); virtual void Unk_06(); virtual void Unk_07(); virtual void Unk_08();
    virtual void Unk_09(); virtual void Unk_0A(); virtual void Unk_0B(); virtual void Unk_0C();
    virtual void Unk_0D(); virtual void Unk_0E(); virtual void Unk_0F(); virtual void Unk_10();
    virtual void Unk_11(); virtual void Unk_12(); virtual void Unk_13(); virtual void Unk_14();
    virtual GFxMovieRoot* GetMovieRoot() const;  // A8
};

class GASEnvironment
{
public:
    bool IsVerboseActionErrors() const;

    std::uint8_t    unk00[0xE8];  // 00
    GFxASCharacter* target;       // E8
};
