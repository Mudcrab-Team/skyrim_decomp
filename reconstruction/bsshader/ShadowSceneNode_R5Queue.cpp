// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original; the listing and community declarations, BSTArray and NiPointer shapes after the sibling
// Adapted bodies: BSSpinLock::Unlock (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp, MIT) inlined
// 0x150e090 ShadowSceneNode::ClearLightArrays
// 0x150e680 ShadowSceneNode::QueueLightRemoveUnscoped
// 0x150e5e0 ShadowSceneNode::QueueLightRemoveByNode
// CI hash: 0x150e090 ?ClearLightArrays@ShadowSceneNode@@QEAAXXZ
// CI hash: 0x150e5e0 ?QueueLightRemoveByNode@ShadowSceneNode@@QEAAXPEAVNiLight@@@Z
// CI hash: 0x150e680 ?QueueLightRemoveUnscoped@ShadowSceneNode@@QEAAXPEAVBSLight@@@Z
#include <intrin.h>
#include "ShadowSceneNode_R5Queue.h"

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

// FindActiveLight, QueueLightAdd: the engine compiled these into the same unit as their callers. With the bodies in view the compiler
// knows the calls leave the argument and the local smart pointers alone, which fixes the exception states and the register use of the callers.
BSLight* ShadowSceneNode::FindActiveLight(NiLight* a_light)
{
    for (auto it = activeLights.begin(); it != activeLights.end(); ++it) {
        BSLight* entry = *it;
        if (entry && entry->light == a_light) {
            return entry;
        }
    }
    for (auto it = shadowLights.begin(); it != shadowLights.end(); ++it) {
        BSLight* entry = *it;
        if (entry && entry->light == a_light) {
            return entry;
        }
    }
    return nullptr;
}

void ShadowSceneNode::QueueLightAdd(const NiPointer<BSLight>& a_light)
{
    if (a_light.m_pObject && allowLightRemoveQueues) {
        BSAutoLock lock(&lightQueueLock);
        MemoryContextScope scope(0x1D);
        queuedRemove.Add(a_light);
    }
}

// ClearLightArrays: CRASHLOGGER_PDB(59818@2026.10.24)
void ShadowSceneNode::ClearLightArrays()
{
    for (auto it = activeLights.begin(); it != activeLights.end(); ++it) {
        BSLight* entry = *it;
        if (entry) {
            NiPointer<BSLight> light(entry);
            QueueLightAdd(light);
        }
    }
    for (auto it = shadowLights.begin(); it != shadowLights.end(); ++it) {
        BSLight* entry = *it;
        if (entry) {
            NiPointer<BSLight> light(entry);
            QueueLightAdd(light);
        }
    }
    for (std::uint32_t i = 0; i < shadowCasterLights.iSize; ++i) {
        BSShadowLight* light = shadowCasterLights[i];
        if (light) {
            light->shadowmapIndex = 0xFF;
            shadowCasterLights[i] = nullptr;
        }
    }
}

// QueueLightRemoveByNode, QueueLightRemoveUnscoped: GUESS(low); no public name
void ShadowSceneNode::QueueLightRemoveByNode(NiLight* a_light)
{
    BSLight* light = FindActiveLight(a_light);
    if (light) {
        BSAutoLock lock(&lightQueueLock);
        lightQueueRemove.Append(light);
    }
}

void ShadowSceneNode::QueueLightRemoveUnscoped(BSLight* a_light)
{
    if (a_light) {
        BSAutoLock lock(&lightQueueLock);
        lightQueueRemove.Append(a_light);
    }
}
