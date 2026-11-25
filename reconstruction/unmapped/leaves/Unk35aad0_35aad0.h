// Source exposure: mixed (community headers; compared functions from the pinned image; a permitted sibling).
// Code origin: declarations and body adapted from a permitted sibling, offsets and call targets checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Script::ModAmountStolenSoldFunction: CRASHLOGGER_PDB(59818@2026.10.24)
// Script_ParseParameters: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); sibling name, identity with this image's callee unproven
// Script, SCRIPT_PARAMETER, ScriptLocals, TESObjectREFR, PlayerCharacter: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the compared function touches
// Unk35aad0, PlayerCharacter::singleton, PlayerCharacter::ModAmountSoldStolen, PlayerCharacter::amountSoldStolen, PlayerCharacter::unknown: GUESS(low); the first is the unit's placeholder owner, the second is spelled after the sibling's helper
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesscriptfunctions.cpp:34153
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesscriptfunctions.cpp:3890
#pragma once

#include <cstdint>

struct SCRIPT_PARAMETER;
class ScriptLocals;
class TESObjectREFR;

// Placeholder owner of the compared function in the image inventory.
class Unk35aad0
{
};

class Script
{
public:
    static bool ModAmountStolenSoldFunction(const SCRIPT_PARAMETER* a_paramInfo, const char* a_scriptData, TESObjectREFR* a_thisObj,
        TESObjectREFR* a_containingObj, Script* a_scriptObj, ScriptLocals* a_locals, double& a_result, std::uint32_t& a_opcodeOffsetPtr);
};

extern bool Script_ParseParameters(const SCRIPT_PARAMETER* a_paramInfo, const char* a_scriptData, std::uint32_t* a_opcodeOffsetPtr,
    TESObjectREFR* a_thisObj, TESObjectREFR* a_containingObj, Script* a_scriptObj, ScriptLocals* a_locals, ...);

class PlayerCharacter
{
public:
    void ModAmountSoldStolen(std::int32_t a_amount) { amountSoldStolen += a_amount; }

    static PlayerCharacter* singleton;

    std::uint8_t unknown[0x91c];
    std::int32_t amountSoldStolen;  // 91C
};
