// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// 0x1d5c00 BGSDestructibleObjectForm::UnloadReplacementModels
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSDestructibleObjectForm, data, replacementModelRefCount, preloadedReplacementModels: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// UnloadReplacementModels: SYMBOLS(fnv-x360-pdb)
#include "BGSDestructibleObjectForm_1d5c00.h"
#include <intrin.h>

// Drop a model user and release the queued load after the last user leaves.
void BGSDestructibleObjectForm::UnloadReplacementModels()
{
    if (data && data->preloadedReplacementModels)
    {
        // Atomic decrement protects concurrent replacement-model users.
        _InterlockedDecrement(&data->replacementModelRefCount);
        if (data->replacementModelRefCount <= 0)
        {
            QueuedFile* old = data->preloadedReplacementModels;
            if (old)
            {
                data->preloadedReplacementModels = nullptr;
                // Atomic release destroys the queued file only for its last owner.
                if (_InterlockedExchangeAdd(&old->refCount, -1) == 1)
                {
                    delete old;
                }
            }
        }
    }
}
