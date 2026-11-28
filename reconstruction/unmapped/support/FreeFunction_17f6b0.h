// Source exposure: binary-analysis (pinned image listing).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Function17f6b0, treated as adapted: shaped like BSSimpleList::RemoveAll in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// SPDX-License-Identifier: CC0-1.0
// Node17f6b0, Function17f6b0, value, next, node, destroyCallback, context: GUESS(low)
#pragma once

struct Node17f6b0
{
    using DestroyCallback = void (*)(Node17f6b0*, void*);

    void* value;       // 0x00
    Node17f6b0* next;  // 0x08

    ~Node17f6b0();
};
static_assert(sizeof(Node17f6b0) == 0x10, "Node17f6b0 size");

void Function17f6b0(Node17f6b0* node, Node17f6b0::DestroyCallback destroyCallback, void* context);
