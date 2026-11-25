// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseOrdered5, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x14c910 BSTArrayEraseOrdered5::Op14c910
// 0x17f280 BSTArrayEraseOrdered5::Op17f280
// 0x17f2e0 BSTArrayEraseOrdered5::Op17f2e0
// 0x190200 BSTArrayEraseOrdered5::Op190200
// 0x190260 BSTArrayEraseOrdered5::Op190260
// 0x1c8fa0 BSTArrayEraseOrdered5::Op1c8fa0
// 0x1c9000 BSTArrayEraseOrdered5::Op1c9000
// 0x2539d0 BSTArrayEraseOrdered5::Op2539d0
// 0x26ffe0 BSTArrayEraseOrdered5::Op26ffe0
// 0x29ded0 BSTArrayEraseOrdered5::Op29ded0
// 0x29df30 BSTArrayEraseOrdered5::Op29df30
// 0x2fbb80 BSTArrayEraseOrdered5::Op2fbb80
// 0x309f30 BSTArrayEraseOrdered5::Op309f30
// 0x3257d0 BSTArrayEraseOrdered5::Op3257d0
// 0x328850 BSTArrayEraseOrdered5::Op328850
// 0x38fbe0 BSTArrayEraseOrdered5::Op38fbe0
// 0x398a90 BSTArrayEraseOrdered5::Op398a90
// 0x3a41b0 BSTArrayEraseOrdered5::Op3a41b0
// 0x3a4210 BSTArrayEraseOrdered5::Op3a4210
// 0x3a4270 BSTArrayEraseOrdered5::Op3a4270
// 0x3aaa50 BSTArrayEraseOrdered5::Op3aaa50
// 0x3aaab0 BSTArrayEraseOrdered5::Op3aaab0
// 0x3cd6e0 BSTArrayEraseOrdered5::Op3cd6e0
// 0x3e0440 BSTArrayEraseOrdered5::Op3e0440
// 0x3e04a0 BSTArrayEraseOrdered5::Op3e04a0
// 0x3e0500 BSTArrayEraseOrdered5::Op3e0500
// 0x3e0560 BSTArrayEraseOrdered5::Op3e0560
// 0x3ec4f0 BSTArrayEraseOrdered5::Op3ec4f0
// 0x3ec550 BSTArrayEraseOrdered5::Op3ec550
// 0x3ec5b0 BSTArrayEraseOrdered5::Op3ec5b0
#include "BSTArrayEraseOrdered5.h"

void BSTArrayEraseOrdered5::Op14c910(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 16u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op17f280(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 16u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op17f2e0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 4u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op190200(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op190260(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op1c8fa0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op1c9000(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op2539d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op26ffe0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 16u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op29ded0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 24u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op29df30(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 24u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op2fbb80(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op309f30(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op3257d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op328850(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 4u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op38fbe0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op398a90(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op3a41b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op3a4210(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op3a4270(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op3aaa50(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op3aaab0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op3cd6e0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op3e0440(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op3e04a0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op3e0500(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op3e0560(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op3ec4f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 2u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op3ec550(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 4u);
    self->size -= count;
}

void BSTArrayEraseOrdered5::Op3ec5b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 8u);
    self->size -= count;
}

