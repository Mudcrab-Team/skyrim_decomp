// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ScriptLocals, ScriptLocals::ClearActionFlags: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x341a60 ScriptLocals::ClearActionFlags
#include "ScriptLocals_341a60.h"

// Clears action flags on every action entry in the list.
void ScriptLocals::ClearActionFlags()
{
    ActionNode* node = actionList;
    while (node != nullptr)
    {
        ActionObject* item = node->item;
        if (item == nullptr)
        {
            break;
        }
        node = node->next;
        item->flags = 0;
    }
}
