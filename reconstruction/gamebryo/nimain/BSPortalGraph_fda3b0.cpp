// Source exposure: mixed (local pinned-image analysis and declared community hypotheses).
// Code origin: original graph reconstruction with adapted community lock release.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: PortalMutex::Unlock follows BSSpinLock::Unlock (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp, MIT).
// 0xfda3b0 BSPortalGraph::StageAlwaysRenderChildAdd
// CI hash: 0xfda3b0 ?StageAlwaysRenderChildAdd@BSPortalGraph@@QEAAXPEAUNiAVObject@@@Z
#include "BSPortalGraph_fda3b0.h"

void BSPortalGraph::StageAlwaysRenderChildAdd(NiAVObject* child)
{
    if (child) {
        graphLock.Lock(0);
        if (pendingAdds.Find(child) == ~0u) {
            pendingAdds.AppendEntry(child);
            unsigned int index = pendingRemoves.Find(child);
            if (index != ~0u)
                pendingRemoves.RemoveRange(index, 1);
        }
        graphLock.Unlock();
    }
}
