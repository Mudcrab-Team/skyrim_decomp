// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayRelease, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x111b60 BSTArrayRelease::Op111b60
// 0x11a4e0 BSTArrayRelease::Op11a4e0
// 0x11aed0 BSTArrayRelease::Op11aed0
// 0x11af70 BSTArrayRelease::Op11af70
// 0x12c2f0 BSTArrayRelease::Op12c2f0
// 0x136120 BSTArrayRelease::Op136120
// 0x733fc0 BSTArrayRelease::Op733fc0
#include "BSTArrayRelease.h"

void BSTArrayRelease::Op111b60(BSTArrayHeap* self)
{
    if (self->data) {
        ArrayDealloc_ce0ed0(self);
        self->size = 0u;
    }
}

void BSTArrayRelease::Op11a4e0(BSTArrayHeap* self)
{
    if (self->data) {
        ArrayDealloc_ce0ed0(self);
        self->size = 0u;
    }
}

void BSTArrayRelease::Op11aed0(BSTArrayHeap* self)
{
    if (self->data) {
        ArrayDealloc_ce0ed0(self);
        self->size = 0u;
    }
}

void BSTArrayRelease::Op11af70(BSTArrayScrap* self)
{
    if (self->data) {
        ArrayDealloc_ce11f0(self);
        self->size = 0u;
    }
}

void BSTArrayRelease::Op12c2f0(BSTArrayHeap* self)
{
    if (self->data) {
        ArrayDealloc_ce0ed0(self);
        self->size = 0u;
    }
}

void BSTArrayRelease::Op136120(BSTArrayHeap* self)
{
    if (self->data) {
        ArrayDealloc_ce0ed0(self);
        self->size = 0u;
    }
}

void BSTArrayRelease::Op733fc0(BSTArrayHeap* self)
{
    if (self->data) {
        ArrayDealloc_ce0ed0(self);
        self->size = 0u;
    }
}

