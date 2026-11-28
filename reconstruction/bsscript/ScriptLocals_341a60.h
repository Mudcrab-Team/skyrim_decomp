// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ScriptLocals, ScriptLocals::ClearActionFlags, ScriptLocals::actionList: CRASHLOGGER_PDB(59818@2026.10.24)
// ActionObject, ActionNode, form, flags, item, next: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct ActionObject
{
    void* form;
    std::uint32_t flags;
};

struct ActionNode
{
    ActionObject* item;
    ActionNode* next;
};

class ScriptLocals
{
public:
    void ClearActionFlags();

    std::uint8_t unk00[0x10];
    ActionNode* actionList;
};

static_assert(offsetof(ActionObject, flags) == 0x08, "flags offset");
static_assert(offsetof(ScriptLocals, actionList) == 0x10, "actionList offset");
