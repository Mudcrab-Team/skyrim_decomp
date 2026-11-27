// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original; the listing and community declarations
// Adapted bodies: BSSpinLock::Unlock (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp, MIT) inlined
// 0x150e780 ShadowSceneNode::AttachObjectToList
// 0x150e1f0 ShadowSceneNode::UpdateAlwaysRenderObject
// CI hash: 0x150e1f0 ?UpdateAlwaysRenderObject@ShadowSceneNode@@QEAAXPEAVNiAVObject@@_N1@Z
// CI hash: 0x150e780 ?AttachObjectToList@ShadowSceneNode@@QEAAXPEAVNiAVObject@@_N@Z
#include <intrin.h>
#include "ShadowSceneNode_Tls.h"

// The lock release is inlined into every guard, as the engine does.
void BSSpinLock::Unlock()
{
    _mm_lfence();  // ordering: serialise earlier loads before reading the owner
    std::uint32_t myThreadID = GetCurrentThreadId();

    if (owningThread == myThreadID) {
        if (lockCount == 1) {
            owningThread = 0;
            _mm_mfence();  // ordering: publish the cleared owner before releasing the count
            // atomic release: other threads spin on this count
            _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&lockCount), 0, 1);
        } else {
            // atomic release: other threads spin on this count
            _InterlockedDecrement(reinterpret_cast<volatile long*>(&lockCount));
        }
    }
}

// AttachObjectToList, UpdateAlwaysRenderObject: GUESS(low); no public name. The PDB name DetachAlwaysRenderChild of 0x150e1f0 does not fit: the body
// appends the object to its list and registers or removes it with the portal graph according to the last flag.
// PrepareAlwaysRenderObject: GUESS(low); the object-side step before an object joins the always-render list
void PrepareAlwaysRenderObject(NiAVObject* a_object);

void ShadowSceneNode::AttachObjectToList(NiAVObject* a_object, bool a_secondary)
{
    if (a_object) {
        BSAutoLock lock(&objectListLock);
        MemoryContextScope scope(0x20);
        if (!a_secondary) {
            particleNodes.Append(a_object);
        } else {
            attachedNodes.Append(a_object);
        }
    }
}

void ShadowSceneNode::UpdateAlwaysRenderObject(NiAVObject* a_object, bool a_notify, bool a_add)
{
    BSAutoLock lock(&objectListLock);
    if (a_object) {
        MemoryContextScope scope(0x20);
        PrepareAlwaysRenderObject(a_object);
        alwaysRenderObjects.Append(a_object);
        if (a_notify && portalGraph) {
            if (a_add) {
                portalGraph->AddAlwaysRenderChild(a_object);
            } else {
                portalGraph->RemoveAlwaysRenderChild(a_object);
            }
        }
    }
}
