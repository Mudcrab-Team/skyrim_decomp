// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSShaderProperty, RenderPassArray, Clear: CRASHLOGGER_PDB(59818@2026.10.24)
// PassEntry, nextEntry: GUESS(low)
// 0x3f1010 BSShaderProperty::RenderPassArray::Clear
#include "BSShaderProperty_3f1010.h"

// Destroy each owned entry before clearing the list head.
void BSShaderProperty::RenderPassArray::Clear()
{
    PassEntry* entry = head;
    while (entry) {
        PassEntry* next = entry->nextEntry;
        delete entry;
        entry = next;
    }
    head = nullptr;
}
