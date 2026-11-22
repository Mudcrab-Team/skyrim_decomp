// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseOrdered1, helper structs, methods and referenced symbols: GUESS(low) STANDIN
// Adapted bodies: none
// 0x391110 BSTArrayEraseOrdered1::Op391110
#include "BSTArrayEraseOrdered1.h"

void BSTArrayEraseOrdered1::Op391110(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
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

