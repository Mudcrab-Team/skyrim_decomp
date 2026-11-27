// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseUnordered1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x1b5660 BSTArrayEraseUnordered1::Op1b5660
// 0x1ef3d0 BSTArrayEraseUnordered1::Op1ef3d0
// 0x242080 BSTArrayEraseUnordered1::Op242080
// 0x280e40 BSTArrayEraseUnordered1::Op280e40
// 0x286090 BSTArrayEraseUnordered1::Op286090
// 0x286180 BSTArrayEraseUnordered1::Op286180
// 0x29df90 BSTArrayEraseUnordered1::Op29df90
// 0x2d5fa0 BSTArrayEraseUnordered1::Op2d5fa0
// 0x2fbca0 BSTArrayEraseUnordered1::Op2fbca0
// 0x31c2f0 BSTArrayEraseUnordered1::Op31c2f0
// 0x398af0 BSTArrayEraseUnordered1::Op398af0
// 0x39c5b0 BSTArrayEraseUnordered1::Op39c5b0
// 0x3cd7f0 BSTArrayEraseUnordered1::Op3cd7f0
// 0x3e0920 BSTArrayEraseUnordered1::Op3e0920
// 0x3e0980 BSTArrayEraseUnordered1::Op3e0980
// 0x4857d0 BSTArrayEraseUnordered1::Op4857d0
// 0x4b8bd0 BSTArrayEraseUnordered1::Op4b8bd0
// 0x53de60 BSTArrayEraseUnordered1::Op53de60
// 0x53dec0 BSTArrayEraseUnordered1::Op53dec0
// 0x5b9980 BSTArrayEraseUnordered1::Op5b9980
// 0x5b99e0 BSTArrayEraseUnordered1::Op5b99e0
// 0x5eb900 BSTArrayEraseUnordered1::Op5eb900
// 0x5eb960 BSTArrayEraseUnordered1::Op5eb960
// 0x60b280 BSTArrayEraseUnordered1::Op60b280
// 0x6303c0 BSTArrayEraseUnordered1::Op6303c0
// 0x63e180 BSTArrayEraseUnordered1::Op63e180
// 0x6450c0 BSTArrayEraseUnordered1::Op6450c0
// 0x647330 BSTArrayEraseUnordered1::Op647330
// 0x64ce40 BSTArrayEraseUnordered1::Op64ce40
// 0x664070 BSTArrayEraseUnordered1::Op664070
#include "BSTArrayEraseUnordered1.h"

void BSTArrayEraseUnordered1::Op1b5660(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op1ef3d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op242080(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op280e40(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op286090(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op286180(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op29df90(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op2d5fa0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op2fbca0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op31c2f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op398af0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op39c5b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op3cd7f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op3e0920(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op3e0980(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 4u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op4857d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op4b8bd0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op53de60(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op53dec0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op5b9980(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op5b99e0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op5eb900(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op5eb960(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op60b280(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op6303c0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op63e180(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op6450c0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op647330(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op64ce40(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered1::Op664070(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

