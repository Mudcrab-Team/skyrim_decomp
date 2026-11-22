// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// SPDX-License-Identifier: CC0-1.0
// ExtraTextDisplayData: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// displayName, displayNameText, ownerQuest, ownerInstance, temperFactor, customNameLength: CRASHLOGGER_PDB(59818@2026.10.24)
// Function189930, ParseQuestText: GUESS(low); placeholder names for the method and its callee
#pragma once
#include <cstdint>
#include "BSExtraData.h"

class BGSMessage;
class BSString;
class TESQuest;

BSString* ParseQuestText(BSString* a_text, TESQuest* a_quest, std::int32_t a_instance);

// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class ExtraTextDisplayData : public BSExtraData
{
public:
    BSString* Function189930(BSString* a_text) const;
    virtual std::uint32_t GetType() const;

    const char* displayName;         // 10
    BGSMessage* displayNameText;     // 18
    TESQuest* ownerQuest;            // 20
    std::int32_t ownerInstance;      // 28
    float temperFactor;              // 2C
    std::uint16_t customNameLength;  // 30
    std::uint16_t pad32;             // 32
    std::uint32_t pad34;             // 34
};
