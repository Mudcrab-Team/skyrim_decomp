// New function names and signatures, unknown global names, and newly split unknown regions: GUESS(low); declarations follow the observed operations.
// Code origin: declarations retained from the labelled existing local unit; new members inferred from the local listing.
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESLevCharacter: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject, TESBoundAnimObject: STANDIN EXE_RTTI
// TESLevCharacter::InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown20, unknown30, unknown58: GUESS(low); NG models the two sub-objects at 0x30 and 0x58 as bases, here they are byte regions passed by address
// InitLeveledListState, InitModelTextureSwapState, ResetOwnerState: GUESS(low); callees at 0x1e9d60, 0x1ed110 and 0x1e60b0, declared and bound by hint
#pragma once
#include <cstdint>

namespace ReconstructedTESLevCharacter {


#include <cstdint>
#include "TESForm.h"

class TESLevCharacter;

// Callees of InitItemImpl; declared, not defined here.
void InitLeveledListState(void* a_list, TESLevCharacter* a_owner);
void InitModelTextureSwapState(void* a_swap, TESLevCharacter* a_owner);
void ResetOwnerState(TESLevCharacter* a_owner, bool a_flag);


class TESObject : public TESForm
{
public:
};

class TESBoundObject : public TESObject
{
public:
};

class TESBoundAnimObject : public TESBoundObject
{
public:
};

class TESLevCharacter : public TESBoundAnimObject
{
public:
    bool Function271830(std::uint8_t a_type);

public:
    static std::uint32_t Function271820();

public:
    virtual void InitItemImpl();  // compared: 0x2717b0

    std::uint8_t unknown20[0x10];  // 20
    std::uint8_t unknown30[0x28];  // 30
    std::uint8_t unknown58[0x18];  // 58
};

extern std::uint32_t unknownLeveledCharacterState207acc0;

}
