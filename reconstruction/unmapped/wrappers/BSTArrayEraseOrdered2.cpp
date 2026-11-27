// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseOrdered2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x3ec610 BSTArrayEraseOrdered2::Op3ec610
// 0x3ec670 BSTArrayEraseOrdered2::Op3ec670
// 0x4680d0 BSTArrayEraseOrdered2::Op4680d0
// 0x48d300 BSTArrayEraseOrdered2::Op48d300
// 0x4c80b0 BSTArrayEraseOrdered2::Op4c80b0
// 0x4d5020 BSTArrayEraseOrdered2::Op4d5020
// 0x51c770 BSTArrayEraseOrdered2::Op51c770
// 0x535bb0 BSTArrayEraseOrdered2::Op535bb0
// 0x539f10 BSTArrayEraseOrdered2::Op539f10
// 0x53dda0 BSTArrayEraseOrdered2::Op53dda0
// 0x53de00 BSTArrayEraseOrdered2::Op53de00
// 0x56f980 BSTArrayEraseOrdered2::Op56f980
// 0x577ec0 BSTArrayEraseOrdered2::Op577ec0
// 0x5ff740 BSTArrayEraseOrdered2::Op5ff740
// 0x60b220 BSTArrayEraseOrdered2::Op60b220
// 0x60d560 BSTArrayEraseOrdered2::Op60d560
// 0x630270 BSTArrayEraseOrdered2::Op630270
// 0x645bc0 BSTArrayEraseOrdered2::Op645bc0
// 0x6c2410 BSTArrayEraseOrdered2::Op6c2410
// 0x6c2470 BSTArrayEraseOrdered2::Op6c2470
// 0x71f290 BSTArrayEraseOrdered2::Op71f290
// 0x771e70 BSTArrayEraseOrdered2::Op771e70
// 0x771ed0 BSTArrayEraseOrdered2::Op771ed0
// 0x771fb0 BSTArrayEraseOrdered2::Op771fb0
// 0x7b4b50 BSTArrayEraseOrdered2::Op7b4b50
// 0x805630 BSTArrayEraseOrdered2::Op805630
// 0x8095b0 BSTArrayEraseOrdered2::Op8095b0
// 0x812fd0 BSTArrayEraseOrdered2::Op812fd0
// 0x861850 BSTArrayEraseOrdered2::Op861850
// 0x8618b0 BSTArrayEraseOrdered2::Op8618b0
#include "BSTArrayEraseOrdered2.h"

void BSTArrayEraseOrdered2::Op3ec610(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op3ec670(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op4680d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op48d300(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op4c80b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op4d5020(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op51c770(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op535bb0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op539f10(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op53dda0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op53de00(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 56u);
    self->size -= count;
}

void BSTArrayEraseOrdered2::Op56f980(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 12u);
    self->size -= count;
}

void BSTArrayEraseOrdered2::Op577ec0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op5ff740(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op60b220(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op60d560(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op630270(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op645bc0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op6c2410(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op6c2470(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op71f290(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op771e70(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op771ed0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op771fb0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op7b4b50(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op805630(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op8095b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op812fd0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered2::Op861850(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 36u);
    self->size -= count;
}

void BSTArrayEraseOrdered2::Op8618b0(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count)
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

