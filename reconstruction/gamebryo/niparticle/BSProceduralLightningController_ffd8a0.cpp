// SPDX-License-Identifier: GPL-3.0
// 0xffd8a0 BSProceduralLightningController::SetInterpolator
// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// Sibling source: fo4-private@1b765c70 src/BSMain/BSProceduralLightningController.cpp:87
// SetInterpolator body uses the permitted sibling ownership shape.
// SetInterpolator: SIBLING(fo4-private@1b765c70, author-permission)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSProceduralLightningController, interpolators: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// SetInterpolator: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiInterpolator, DeleteThis, _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#include "BSProceduralLightningController_ffd8a0.h"
#include <intrin.h>

void BSProceduralLightningController::SetInterpolator(NiInterpolator* interpolator, std::uint16_t index)
{
    NiInterpolator* old = interpolators[index];
    if (old != interpolator) {
        if (interpolator) {
            // Reference ownership may be shared across threads.
            _InterlockedIncrement(&interpolator->_refCount);
        }
        interpolators[index] = interpolator;
        if (old) {
            // Atomically release the previous reference and destroy its last owner.
            if (_InterlockedDecrement(&old->_refCount) == 0) {
                old->DeleteThis();
            }
        }
    }
}
