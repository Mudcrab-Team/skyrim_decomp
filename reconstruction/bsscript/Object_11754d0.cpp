// Source exposure: mixed (the listing of the pinned image; names from the sibling declarations used by the adapted body).
// Code origin: body adapted from the sibling function below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/BSScript/BSScriptObject.inl:5
// 0x11754d0 BSScript::Object::operator delete
// CI hash: 0x11754d0 ??3Object@BSScript@@SAXPEAX@Z
#include "Object_11754d0.h"

void BSScript::Object::operator delete(void* apMemory)
{
    if (apMemory) {
        MemoryManager::Instance().Deallocate(apMemory, false);
    }
}
