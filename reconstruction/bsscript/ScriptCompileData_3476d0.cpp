// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x3476d0 ScriptCompileData::VerifyReferencedObjectList
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptCompiler.cpp:231
#include "ScriptCompileData_3476d0.h"

bool ScriptCompileData::VerifyReferencedObjectList()
{
    auto* node = &listRefObjects._listHead;
    while (node)
    {
        auto* item = node->item;
        if (!item)
            return true;
        node = node->next;
        if (!item->form && !item->variableID)
        {
            ScriptCompiler::ScriptError(this, "Unknown referenced object '%s'.", item->editorID.data ? item->editorID.data : "");
            return false;
        }
    }
    return true;
}
