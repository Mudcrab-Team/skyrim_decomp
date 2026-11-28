// Source exposure: mixed (pinned image listing; community source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: NiPointer25d4c0::operator=, NiRefObject25d4c0::IncRefCount and DecRefCount, treated as adapted: shaped like NiPointer::operator= and NiRefObject::IncRefCount and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/N/NiRefObject.cpp:22, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x25d4c0 BGSArtObjectCloneTask::Function25d4c0
#include "BGSArtObjectCloneTask.h"

// Clones the source art object into the task's smart pointer and publishes it with a memory fence.
bool BGSArtObjectCloneTask::Function25d4c0()
{
    if (sourceObject) {
        cloned = sourceObject->CloneObject(nullptr, nullptr);
        // memory barrier publishing cloned object across task threads
        _mm_mfence();
    }
    return false;
}
