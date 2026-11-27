// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseOrdered4, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x1514470 BSTArrayEraseOrdered4::Op1514470
// 0x15144d0 BSTArrayEraseOrdered4::Op15144d0
// 0x1569b30 BSTArrayEraseOrdered4::Op1569b30
#include "BSTArrayEraseOrdered4.h"

void BSTArrayEraseOrdered4::Op1514470(BSTArrayScrap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered4::Op15144d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

void BSTArrayEraseOrdered4::Op1569b30(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

