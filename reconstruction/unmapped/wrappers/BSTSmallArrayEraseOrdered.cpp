// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTSmallArrayEraseOrdered, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x2fe700 BSTSmallArrayEraseOrdered::Op2fe700
// 0x5c2fa0 BSTSmallArrayEraseOrdered::Op5c2fa0
// 0x5eb880 BSTSmallArrayEraseOrdered::Op5eb880
// 0x771f30 BSTSmallArrayEraseOrdered::Op771f30
// 0x873dd0 BSTSmallArrayEraseOrdered::Op873dd0
// 0x924e40 BSTSmallArrayEraseOrdered::Op924e40
// 0xbdb950 BSTSmallArrayEraseOrdered::Opbdb950
// 0xce31b0 BSTSmallArrayEraseOrdered::Opce31b0
#include "BSTSmallArrayEraseOrdered.h"

void BSTSmallArrayEraseOrdered::Op2fe700(BSTSmallArray_8* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    if (count == size) {
        if (self->Data()) {
            self->size = 0u;
        }
        return;
    }
    std::uint32_t tail = size - pos - count;
    ArrayMove_ce0980(&self->size, self->Data(), pos, pos + count, tail, 8u);
    self->size -= count;
}

void BSTSmallArrayEraseOrdered::Op5c2fa0(BSTSmallArray_8* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    if (count == size) {
        if (self->Data()) {
            self->size = 0u;
        }
        return;
    }
    std::uint32_t tail = size - pos - count;
    ArrayMove_ce0980(&self->size, self->Data(), pos, pos + count, tail, 4u);
    self->size -= count;
}

void BSTSmallArrayEraseOrdered::Op5eb880(BSTSmallArray_16* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    if (count == size) {
        if (self->Data()) {
            self->size = 0u;
        }
        return;
    }
    std::uint32_t tail = size - pos - count;
    ArrayMove_ce0980(&self->size, self->Data(), pos, pos + count, tail, 8u);
    self->size -= count;
}

void BSTSmallArrayEraseOrdered::Op771f30(BSTSmallArray_32* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    if (count == size) {
        if (self->Data()) {
            self->size = 0u;
        }
        return;
    }
    std::uint32_t tail = size - pos - count;
    ArrayMove_ce0980(&self->size, self->Data(), pos, pos + count, tail, 16u);
    self->size -= count;
}

void BSTSmallArrayEraseOrdered::Op873dd0(BSTSmallArray_32* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    if (count == size) {
        if (self->Data()) {
            self->size = 0u;
        }
        return;
    }
    std::uint32_t tail = size - pos - count;
    ArrayMove_ce0980(&self->size, self->Data(), pos, pos + count, tail, 8u);
    self->size -= count;
}

void BSTSmallArrayEraseOrdered::Op924e40(BSTSmallArray_16* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    if (count == size) {
        if (self->Data()) {
            self->size = 0u;
        }
        return;
    }
    std::uint32_t tail = size - pos - count;
    ArrayMove_ce0980(&self->size, self->Data(), pos, pos + count, tail, 4u);
    self->size -= count;
}

void BSTSmallArrayEraseOrdered::Opbdb950(BSTSmallArray_24* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    if (count == size) {
        if (self->Data()) {
            self->size = 0u;
        }
        return;
    }
    std::uint32_t tail = size - pos - count;
    ArrayMove_ce0980(&self->size, self->Data(), pos, pos + count, tail, 24u);
    self->size -= count;
}

void BSTSmallArrayEraseOrdered::Opce31b0(BSTSmallArray_16* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    if (count == size) {
        if (self->Data()) {
            self->size = 0u;
        }
        return;
    }
    std::uint32_t tail = size - pos - count;
    ArrayMove_ce0980(&self->size, self->Data(), pos, pos + count, tail, 4u);
    self->size -= count;
}

