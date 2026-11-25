// Source exposure: mixed (community headers; the pinned image listing; a permitted sibling body).
// Code origin: body adapted from a permitted sibling body, argument order and offsets checked against the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x35aad0 Script::ModAmountStolenSoldFunction
// Adapted bodies: Script::ModAmountStolenSoldFunction (from Cmd_ModAmountSoldStolen_Execute)
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesscriptfunctions.cpp:34153
#include "Unk35aad0_35aad0.h"

// Script command: parses one integer and adds it to the player's sold-and-stolen total.
bool Script::ModAmountStolenSoldFunction(const SCRIPT_PARAMETER* a_paramInfo, const char* a_scriptData, TESObjectREFR* a_thisObj,
    TESObjectREFR* a_containingObj, Script* a_scriptObj, ScriptLocals* a_locals, double& a_result, std::uint32_t& a_opcodeOffsetPtr)
{
    std::int32_t amount = 0;
    if (!Script_ParseParameters(a_paramInfo, a_scriptData, &a_opcodeOffsetPtr, a_thisObj, a_containingObj, a_scriptObj, a_locals, &amount)) {
        return false;
    }
    PlayerCharacter::singleton->ModAmountSoldStolen(amount);
    return true;
}
