// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayResizeTrivial3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x11eb340 BSTArrayResizeTrivial3::Op11eb340
// 0x11ef780 BSTArrayResizeTrivial3::Op11ef780
// 0x11ef800 BSTArrayResizeTrivial3::Op11ef800
// 0x11f24e0 BSTArrayResizeTrivial3::Op11f24e0
// 0x11f2560 BSTArrayResizeTrivial3::Op11f2560
// 0x1202ad0 BSTArrayResizeTrivial3::Op1202ad0
// 0x1202b50 BSTArrayResizeTrivial3::Op1202b50
// 0x12508f0 BSTArrayResizeTrivial3::Op12508f0
// 0x125c1b0 BSTArrayResizeTrivial3::Op125c1b0
// 0x12732e0 BSTArrayResizeTrivial3::Op12732e0
// 0x1273360 BSTArrayResizeTrivial3::Op1273360
// 0x14e9e90 BSTArrayResizeTrivial3::Op14e9e90
// 0x1514770 BSTArrayResizeTrivial3::Op1514770
// 0x1593bf0 BSTArrayResizeTrivial3::Op1593bf0
#include "BSTArrayResizeTrivial3.h"

bool BSTArrayResizeTrivial3::Op11eb340(BSTArrayScrap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize == oldSize) {
            self->size = newSize;
            return true;
        }
        if (newSize > self->capacity) {
            if (self->capacity == 0u) {
                ok = ArrayAlloc_ce1010(self, newSize, 4u);
            } else {
                ok = ArrayRealloc_ce10a0(self, newSize, oldSize, 0u, 0u, 4u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial3::Op11ef780(BSTArrayScrap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize == oldSize) {
            self->size = newSize;
            return true;
        }
        if (newSize > self->capacity) {
            if (self->capacity == 0u) {
                ok = ArrayAlloc_ce1010(self, newSize, 8u);
            } else {
                ok = ArrayRealloc_ce10a0(self, newSize, oldSize, 0u, 0u, 8u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial3::Op11ef800(BSTArrayScrap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize == oldSize) {
            self->size = newSize;
            return true;
        }
        if (newSize > self->capacity) {
            if (self->capacity == 0u) {
                ok = ArrayAlloc_ce1010(self, newSize, 8u);
            } else {
                ok = ArrayRealloc_ce10a0(self, newSize, oldSize, 0u, 0u, 8u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial3::Op11f24e0(BSTArrayHeap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize == oldSize) {
            self->size = newSize;
            return true;
        }
        if (newSize > self->capacity) {
            if (self->capacity == 0u) {
                ok = ArrayAlloc_ce0cd0(self, newSize, 8u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 8u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial3::Op11f2560(BSTArrayHeap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize == oldSize) {
            self->size = newSize;
            return true;
        }
        if (newSize > self->capacity) {
            if (self->capacity == 0u) {
                ok = ArrayAlloc_ce0cd0(self, newSize, 8u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 8u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial3::Op1202ad0(BSTArrayHeap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize == oldSize) {
            self->size = newSize;
            return true;
        }
        if (newSize > self->capacity) {
            if (self->capacity == 0u) {
                ok = ArrayAlloc_ce0cd0(self, newSize, 1u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 1u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial3::Op1202b50(BSTArrayHeap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize == oldSize) {
            self->size = newSize;
            return true;
        }
        if (newSize > self->capacity) {
            if (self->capacity == 0u) {
                ok = ArrayAlloc_ce0cd0(self, newSize, 8u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 8u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial3::Op12508f0(BSTArrayHeap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize == oldSize) {
            self->size = newSize;
            return true;
        }
        if (newSize > self->capacity) {
            if (self->capacity == 0u) {
                ok = ArrayAlloc_ce0cd0(self, newSize, 12u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 12u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial3::Op125c1b0(BSTArrayHeap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize == oldSize) {
            self->size = newSize;
            return true;
        }
        if (newSize > self->capacity) {
            if (self->capacity == 0u) {
                ok = ArrayAlloc_ce0cd0(self, newSize, 4u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 4u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial3::Op12732e0(BSTArrayHeap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize == oldSize) {
            self->size = newSize;
            return true;
        }
        if (newSize > self->capacity) {
            if (self->capacity == 0u) {
                ok = ArrayAlloc_ce0cd0(self, newSize, 4u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 4u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial3::Op1273360(BSTArrayHeap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize == oldSize) {
            self->size = newSize;
            return true;
        }
        if (newSize > self->capacity) {
            if (self->capacity == 0u) {
                ok = ArrayAlloc_ce0cd0(self, newSize, 4u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 4u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial3::Op14e9e90(BSTArrayHeap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize == oldSize) {
            self->size = newSize;
            return true;
        }
        if (newSize > self->capacity) {
            if (self->capacity == 0u) {
                ok = ArrayAlloc_ce0cd0(self, newSize, 8u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 8u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial3::Op1514770(BSTArrayHeap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize == oldSize) {
            self->size = newSize;
            return true;
        }
        if (newSize > self->capacity) {
            if (self->capacity == 0u) {
                ok = ArrayAlloc_ce0cd0(self, newSize, 8u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 8u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial3::Op1593bf0(BSTArrayScrap* self, std::uint32_t newSize)
{
    bool ok = true;
    if (newSize != 0u) {
        std::uint32_t oldSize = self->size;
        if (newSize == oldSize) {
            self->size = newSize;
            return true;
        }
        if (newSize > self->capacity) {
            if (self->capacity == 0u) {
                ok = ArrayAlloc_ce1010(self, newSize, 1u);
            } else {
                ok = ArrayRealloc_ce10a0(self, newSize, oldSize, 0u, 0u, 1u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

