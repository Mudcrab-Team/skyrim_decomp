// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayResizeTrivial1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x17fd90 BSTArrayResizeTrivial1::Op17fd90
// 0x17fe10 BSTArrayResizeTrivial1::Op17fe10
// 0x17fe90 BSTArrayResizeTrivial1::Op17fe90
// 0x1800b0 BSTArrayResizeTrivial1::Op1800b0
// 0x190670 BSTArrayResizeTrivial1::Op190670
// 0x1ecc60 BSTArrayResizeTrivial1::Op1ecc60
// 0x2a0c70 BSTArrayResizeTrivial1::Op2a0c70
// 0x31b220 BSTArrayResizeTrivial1::Op31b220
// 0x31d3d0 BSTArrayResizeTrivial1::Op31d3d0
// 0x326c80 BSTArrayResizeTrivial1::Op326c80
// 0x328950 BSTArrayResizeTrivial1::Op328950
// 0x38fc40 BSTArrayResizeTrivial1::Op38fc40
// 0x391230 BSTArrayResizeTrivial1::Op391230
// 0x39eb80 BSTArrayResizeTrivial1::Op39eb80
// 0x39ec00 BSTArrayResizeTrivial1::Op39ec00
// 0x3cd8e0 BSTArrayResizeTrivial1::Op3cd8e0
// 0x3cd960 BSTArrayResizeTrivial1::Op3cd960
// 0x3e0c40 BSTArrayResizeTrivial1::Op3e0c40
// 0x41e680 BSTArrayResizeTrivial1::Op41e680
// 0x441690 BSTArrayResizeTrivial1::Op441690
// 0x45d540 BSTArrayResizeTrivial1::Op45d540
// 0x48d360 BSTArrayResizeTrivial1::Op48d360
// 0x4c0c10 BSTArrayResizeTrivial1::Op4c0c10
// 0x4c0c90 BSTArrayResizeTrivial1::Op4c0c90
// 0x4c0ee0 BSTArrayResizeTrivial1::Op4c0ee0
// 0x4c8220 BSTArrayResizeTrivial1::Op4c8220
// 0x4e75d0 BSTArrayResizeTrivial1::Op4e75d0
// 0x53df20 BSTArrayResizeTrivial1::Op53df20
// 0x55c5d0 BSTArrayResizeTrivial1::Op55c5d0
// 0x565270 BSTArrayResizeTrivial1::Op565270
#include "BSTArrayResizeTrivial1.h"

bool BSTArrayResizeTrivial1::Op17fd90(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op17fe10(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op17fe90(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op1800b0(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op190670(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op1ecc60(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op2a0c70(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op31b220(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op31d3d0(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op326c80(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op328950(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op38fc40(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op391230(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op39eb80(BSTArrayHeap* self, std::uint32_t newSize)
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
                ok = ArrayAlloc_ce0cd0(self, newSize, 2u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 2u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial1::Op39ec00(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op3cd8e0(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op3cd960(BSTArrayScrap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op3e0c40(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op41e680(BSTArrayScrap* self, std::uint32_t newSize)
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
                ok = ArrayAlloc_ce1010(self, newSize, 24u);
            } else {
                ok = ArrayRealloc_ce10a0(self, newSize, oldSize, 0u, 0u, 24u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial1::Op441690(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op45d540(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op48d360(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op4c0c10(BSTArrayScrap* self, std::uint32_t newSize)
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
                ok = ArrayAlloc_ce1010(self, newSize, 2u);
            } else {
                ok = ArrayRealloc_ce10a0(self, newSize, oldSize, 0u, 0u, 2u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial1::Op4c0c90(BSTArrayHeap* self, std::uint32_t newSize)
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
                ok = ArrayAlloc_ce0cd0(self, newSize, 2u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 2u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial1::Op4c0ee0(BSTArrayHeap* self, std::uint32_t newSize)
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
                ok = ArrayAlloc_ce0cd0(self, newSize, 16u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 16u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial1::Op4c8220(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op4e75d0(BSTArrayHeap* self, std::uint32_t newSize)
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
                ok = ArrayAlloc_ce0cd0(self, newSize, 24u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 24u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial1::Op53df20(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial1::Op55c5d0(BSTArrayHeap* self, std::uint32_t newSize)
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
                ok = ArrayAlloc_ce0cd0(self, newSize, 16u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 16u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial1::Op565270(BSTArrayHeap* self, std::uint32_t newSize)
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

