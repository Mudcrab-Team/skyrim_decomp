// Source exposure: binary-analysis (pinned image listing).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Function17f6b0, treated as adapted: shaped like BSSimpleList::RemoveAll in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// SPDX-License-Identifier: CC0-1.0
// 0x17f6b0 Function17f6b0
#include "FreeFunction_17f6b0.h"

inline Node17f6b0::~Node17f6b0()
{
    Function17f6b0(this, nullptr, nullptr);
}

// Clears the linked chain starting at node->next using destroyCallback or recursive deletion, then zeroes node->value.
void Function17f6b0(Node17f6b0* node, Node17f6b0::DestroyCallback destroyCallback, void* context)
{
    while (node->next != nullptr) {
        Node17f6b0* after = node->next->next;
        node->next->next = nullptr;
        if (destroyCallback != nullptr) {
            destroyCallback(node->next, context);
        } else {
            delete node->next;
        }
        node->next = after;
    }
    node->value = nullptr;
}
