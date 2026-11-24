// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Character: STANDIN GUESS(low); placeholder class, a view of the editor-location member only
// Character::GetEditorInteriorCell: GUESS(low)
// TESForm, TESObjectCELL, formType, cellFlags, editorLocForm, kCell, kIsInteriorCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; editorLocForm sits 8 bytes later in this build
#pragma once

#include <cstdint>
#include <cstddef>

class TESForm
{
public:
    std::uint8_t pad00[0x1A];
    std::uint8_t formType;  // 1A
};

class TESObjectCELL : public TESForm
{
public:
    std::uint8_t  pad1B[0x25];
    std::uint16_t cellFlags;  // 40
};

enum : std::uint8_t
{
    kCell = 0x3C
};

enum : std::uint16_t
{
    kIsInteriorCell = 1 << 0
};

class Character
{
public:
    TESObjectCELL* GetEditorInteriorCell();  // compared: 0x6767e0

    std::uint8_t pad00[0x138];
    TESForm*     editorLocForm;  // 138
};
