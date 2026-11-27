// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseOrdered3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x861910 BSTArrayEraseOrdered3::Op861910
// 0x86f7a0 BSTArrayEraseOrdered3::Op86f7a0
// 0x872a00 BSTArrayEraseOrdered3::Op872a00
// 0x905b10 BSTArrayEraseOrdered3::Op905b10
// 0x915b00 BSTArrayEraseOrdered3::Op915b00
// 0x94cd60 BSTArrayEraseOrdered3::Op94cd60
// 0x964420 BSTArrayEraseOrdered3::Op964420
// 0x98c760 BSTArrayEraseOrdered3::Op98c760
// 0x9a58a0 BSTArrayEraseOrdered3::Op9a58a0
// 0x9a5900 BSTArrayEraseOrdered3::Op9a5900
// 0x9a5960 BSTArrayEraseOrdered3::Op9a5960
// 0x9c19f0 BSTArrayEraseOrdered3::Op9c19f0
// 0xa5d8f0 BSTArrayEraseOrdered3::Opa5d8f0
// 0xa77850 BSTArrayEraseOrdered3::Opa77850
// 0xcf2ef0 BSTArrayEraseOrdered3::Opcf2ef0
// 0xebe360 BSTArrayEraseOrdered3::Opebe360
// 0xfdd350 BSTArrayEraseOrdered3::Opfdd350
// 0xffacb0 BSTArrayEraseOrdered3::Opffacb0
// 0x1051700 BSTArrayEraseOrdered3::Op1051700
// 0x10de120 BSTArrayEraseOrdered3::Op10de120
// 0x11c7150 BSTArrayEraseOrdered3::Op11c7150
// 0x11c71b0 BSTArrayEraseOrdered3::Op11c71b0
// 0x1224410 BSTArrayEraseOrdered3::Op1224410
// 0x1241380 BSTArrayEraseOrdered3::Op1241380
// 0x12507b0 BSTArrayEraseOrdered3::Op12507b0
// 0x1250810 BSTArrayEraseOrdered3::Op1250810
// 0x1251c60 BSTArrayEraseOrdered3::Op1251c60
// 0x1272a60 BSTArrayEraseOrdered3::Op1272a60
// 0x1272ac0 BSTArrayEraseOrdered3::Op1272ac0
// 0x1514410 BSTArrayEraseOrdered3::Op1514410
#include "BSTArrayEraseOrdered3.h"

void BSTArrayEraseOrdered3::Op861910(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op86f7a0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op872a00(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op905b10(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op915b00(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op94cd60(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op964420(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op98c760(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op9a58a0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op9a5900(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op9a5960(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op9c19f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Opa5d8f0(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Opa77850(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Opcf2ef0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Opebe360(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Opfdd350(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Opffacb0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op1051700(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op10de120(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 80u);
    self->size -= count;
}

void BSTArrayEraseOrdered3::Op11c7150(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op11c71b0(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 32u);
    self->size -= count;
}

void BSTArrayEraseOrdered3::Op1224410(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op1241380(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 40u);
    self->size -= count;
}

void BSTArrayEraseOrdered3::Op12507b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op1250810(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op1251c60(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    void* data = self->data;
    if (count == size) {
        if (data) {
            self->size = 0u;
        }
        return;
    }
    ArrayMove_ce0980(&self->size, data, pos, pos + count, size - pos - count, 52u);
    self->size -= count;
}

void BSTArrayEraseOrdered3::Op1272a60(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op1272ac0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered3::Op1514410(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

