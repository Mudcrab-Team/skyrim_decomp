// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2eece0 TESObjectREFR::FindReferenceFor3D
// Adapted bodies: none
#include "TESObjectREFR_2eece0.h"

// Walk up a scene-graph node's parent chain to find the owning reference, handling player first-person and ammunition references.
TESObjectREFR* TESObjectREFR::FindReferenceFor3D(NiAVObject* object)
{
    TESObjectREFR* result = nullptr;
    NiAVObject* playerFirstPerson = nullptr;
    if (gPlayerCharacter) {
        playerFirstPerson = gPlayerCharacter->Get3D1(true);
    }

    while (object && !result) {
        if (object == playerFirstPerson) {
            return gPlayerCharacter;
        }

        BSFadeNode* fadeNode = object->AsFadeNode();
        if (fadeNode) {
            result = fadeNode->userDataF8;
            if (result) {
                if (result->data.objectReference && result->data.objectReference->formType == FormType::Ammo) {
                    TESObjectREFR* parentRef = FindReferenceFor3D(object->parent);
                    if (parentRef) {
                        result = parentRef;
                    }
                }
                break;
            }
        }
        object = object->parent;
    }

    return result;
}
