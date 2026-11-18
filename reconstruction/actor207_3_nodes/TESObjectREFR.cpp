// TESObjectREFR: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// TESObjectREFR: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Node, next, value, GetNodes, FindNodeValue, unknownPrefix: STANDIN GUESS(low); linked structure and free-function argument identity inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x29b350 FindNodeValue
#include "TESObjectREFR.h"
namespace P2073 {
void* FindNodeValue(TESObjectREFR* ref) {
    void* value = nullptr;
    if (ref) {
        Node* node = ref->GetNodes();
        while (node && !value) {
            value = node->value;
            node = node->next;
        }
    }
    return value;
}
}
