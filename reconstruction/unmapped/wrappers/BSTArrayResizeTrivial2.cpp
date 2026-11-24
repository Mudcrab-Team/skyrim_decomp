// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayResizeTrivial2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x5652f0 BSTArrayResizeTrivial2::Op5652f0
// 0x71fad0 BSTArrayResizeTrivial2::Op71fad0
// 0x772b30 BSTArrayResizeTrivial2::Op772b30
// 0x772bb0 BSTArrayResizeTrivial2::Op772bb0
// 0x772c30 BSTArrayResizeTrivial2::Op772c30
// 0x772cb0 BSTArrayResizeTrivial2::Op772cb0
// 0x816e80 BSTArrayResizeTrivial2::Op816e80
// 0x861af0 BSTArrayResizeTrivial2::Op861af0
// 0x861b70 BSTArrayResizeTrivial2::Op861b70
// 0x86f800 BSTArrayResizeTrivial2::Op86f800
// 0x872a60 BSTArrayResizeTrivial2::Op872a60
// 0x8e8950 BSTArrayResizeTrivial2::Op8e8950
// 0x9427b0 BSTArrayResizeTrivial2::Op9427b0
// 0x98c860 BSTArrayResizeTrivial2::Op98c860
// 0x9a59c0 BSTArrayResizeTrivial2::Op9a59c0
// 0x9a5a40 BSTArrayResizeTrivial2::Op9a5a40
// 0x9a5ac0 BSTArrayResizeTrivial2::Op9a5ac0
// 0xa6c540 BSTArrayResizeTrivial2::Opa6c540
// 0xbdc0e0 BSTArrayResizeTrivial2::Opbdc0e0
// 0xbdc2f0 BSTArrayResizeTrivial2::Opbdc2f0
// 0xc43190 BSTArrayResizeTrivial2::Opc43190
// 0xf15200 BSTArrayResizeTrivial2::Opf15200
// 0xff99b0 BSTArrayResizeTrivial2::Opff99b0
// 0xffc560 BSTArrayResizeTrivial2::Opffc560
// 0x1062350 BSTArrayResizeTrivial2::Op1062350
// 0x109ea40 BSTArrayResizeTrivial2::Op109ea40
// 0x109ebd0 BSTArrayResizeTrivial2::Op109ebd0
// 0x10c3560 BSTArrayResizeTrivial2::Op10c3560
// 0x11b8c70 BSTArrayResizeTrivial2::Op11b8c70
// 0x11e9e50 BSTArrayResizeTrivial2::Op11e9e50
#include "BSTArrayResizeTrivial2.h"

bool BSTArrayResizeTrivial2::Op5652f0(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op71fad0(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op772b30(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op772bb0(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op772c30(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op772cb0(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op816e80(BSTArrayHeap* self, std::uint32_t newSize)
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
                ok = ArrayAlloc_ce0cd0(self, newSize, 32u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 32u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial2::Op861af0(BSTArrayScrap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op861b70(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op86f800(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op872a60(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op8e8950(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op9427b0(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op98c860(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op9a59c0(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op9a5a40(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op9a5ac0(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Opa6c540(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Opbdc0e0(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Opbdc2f0(BSTArrayScrap* self, std::uint32_t newSize)
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
                ok = ArrayAlloc_ce1010(self, newSize, 16u);
            } else {
                ok = ArrayRealloc_ce10a0(self, newSize, oldSize, 0u, 0u, 16u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial2::Opc43190(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Opf15200(BSTArrayScrap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Opff99b0(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Opffc560(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op1062350(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op109ea40(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op109ebd0(BSTArrayHeap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op10c3560(BSTArrayHeap* self, std::uint32_t newSize)
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
                ok = ArrayAlloc_ce0cd0(self, newSize, 48u);
            } else {
                ok = ArrayRealloc_ce0d50(self, newSize, oldSize, 0u, 0u, 48u);
            }
        }
    }
    if (ok) {
        self->size = newSize;
    }
    return ok;
}

bool BSTArrayResizeTrivial2::Op11b8c70(BSTArrayScrap* self, std::uint32_t newSize)
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

bool BSTArrayResizeTrivial2::Op11e9e50(BSTArrayScrap* self, std::uint32_t newSize)
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

