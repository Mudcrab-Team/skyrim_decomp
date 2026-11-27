// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayResizeConstruct, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x5d06f0 BSTArrayResizeConstruct::Op5d06f0
// 0x773050 BSTArrayResizeConstruct::Op773050
// 0x794c40 BSTArrayResizeConstruct::Op794c40
// 0xff16d0 BSTArrayResizeConstruct::Opff16d0
// 0x121fe40 BSTArrayResizeConstruct::Op121fe40
// 0x121fed0 BSTArrayResizeConstruct::Op121fed0
#include "BSTArrayResizeConstruct.h"

bool BSTArrayResizeConstruct::Op5d06f0(BSTArrayHeap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize != oldSize) {
            if (newSize > self->capacity) {
                if (self->capacity == 0u) {
                    ok = ArrayAlloc_ce0cd0(self, newSize, 12u);
                } else {
                    ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 12u);
                }
                if (ok) {
                    ArrayConstruct_5d0370(self, self->size, newSize - self->size);
                }
            } else if (newSize >= oldSize) {
                ArrayConstruct_5d0370(self, oldSize, newSize - oldSize);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeConstruct::Op773050(BSTArrayHeap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize != oldSize) {
            if (newSize > self->capacity) {
                if (self->capacity == 0u) {
                    ok = ArrayAlloc_ce0cd0(self, newSize, 16u);
                } else {
                    ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 16u);
                }
                if (ok) {
                    ArrayConstruct_76a760(self, self->size, newSize - self->size);
                }
            } else if (newSize >= oldSize) {
                ArrayConstruct_76a760(self, oldSize, newSize - oldSize);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeConstruct::Op794c40(BSTArrayHeap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize != oldSize) {
            if (newSize > self->capacity) {
                if (self->capacity == 0u) {
                    ok = ArrayAlloc_ce0cd0(self, newSize, 44u);
                } else {
                    ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 44u);
                }
                if (ok) {
                    ArrayConstruct_794bf0(self, self->size, newSize - self->size);
                }
            } else if (newSize >= oldSize) {
                ArrayConstruct_794bf0(self, oldSize, newSize - oldSize);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeConstruct::Opff16d0(BSTArrayHeap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize != oldSize) {
            if (newSize > self->capacity) {
                if (self->capacity == 0u) {
                    ok = ArrayAlloc_ce0cd0(self, newSize, 20u);
                } else {
                    ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 20u);
                }
                if (ok) {
                    ArrayConstruct_ff1660(self, self->size, newSize - self->size);
                }
            } else if (newSize >= oldSize) {
                ArrayConstruct_ff1660(self, oldSize, newSize - oldSize);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeConstruct::Op121fe40(BSTArrayScrap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize != oldSize) {
            if (newSize > self->capacity) {
                if (self->capacity == 0u) {
                    ok = ArrayAlloc_ce1010(self, newSize, 64u);
                } else {
                    ok = ArrayRealloc_ce10a0(self, newSize, oldSize, 0u, 0u, 64u);
                }
                if (ok) {
                    ArrayConstruct_121fb70(self, self->size, newSize - self->size);
                }
            } else if (newSize >= oldSize) {
                ArrayConstruct_121fb70(self, oldSize, newSize - oldSize);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeConstruct::Op121fed0(BSTArrayHeap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize != oldSize) {
            if (newSize > self->capacity) {
                if (self->capacity == 0u) {
                    ok = ArrayAlloc_ce0cd0(self, newSize, 64u);
                } else {
                    ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 64u);
                }
                if (ok) {
                    ArrayConstruct_121fc10(self, self->size, newSize - self->size);
                }
            } else if (newSize >= oldSize) {
                ArrayConstruct_121fc10(self, oldSize, newSize - oldSize);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

