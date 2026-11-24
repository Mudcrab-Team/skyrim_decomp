// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseUnordered2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x6640d0 BSTArrayEraseUnordered2::Op6640d0
// 0x664130 BSTArrayEraseUnordered2::Op664130
// 0x6c25e0 BSTArrayEraseUnordered2::Op6c25e0
// 0x6c2640 BSTArrayEraseUnordered2::Op6c2640
// 0x6c26a0 BSTArrayEraseUnordered2::Op6c26a0
// 0x6c2700 BSTArrayEraseUnordered2::Op6c2700
// 0x6c2760 BSTArrayEraseUnordered2::Op6c2760
// 0x6c27c0 BSTArrayEraseUnordered2::Op6c27c0
// 0x6c2820 BSTArrayEraseUnordered2::Op6c2820
// 0x6c2880 BSTArrayEraseUnordered2::Op6c2880
// 0x6c28e0 BSTArrayEraseUnordered2::Op6c28e0
// 0x6c2940 BSTArrayEraseUnordered2::Op6c2940
// 0x6c78f0 BSTArrayEraseUnordered2::Op6c78f0
// 0x6d1d70 BSTArrayEraseUnordered2::Op6d1d70
// 0x6d1dd0 BSTArrayEraseUnordered2::Op6d1dd0
// 0x6d1e30 BSTArrayEraseUnordered2::Op6d1e30
// 0x6dbac0 BSTArrayEraseUnordered2::Op6dbac0
// 0x6dbb20 BSTArrayEraseUnordered2::Op6dbb20
// 0x736ba0 BSTArrayEraseUnordered2::Op736ba0
// 0x73bce0 BSTArrayEraseUnordered2::Op73bce0
// 0x73bd40 BSTArrayEraseUnordered2::Op73bd40
// 0x772320 BSTArrayEraseUnordered2::Op772320
// 0x772380 BSTArrayEraseUnordered2::Op772380
// 0x7723e0 BSTArrayEraseUnordered2::Op7723e0
// 0x772440 BSTArrayEraseUnordered2::Op772440
// 0x7724a0 BSTArrayEraseUnordered2::Op7724a0
// 0x772500 BSTArrayEraseUnordered2::Op772500
// 0x772560 BSTArrayEraseUnordered2::Op772560
// 0x7725c0 BSTArrayEraseUnordered2::Op7725c0
// 0x772620 BSTArrayEraseUnordered2::Op772620
#include "BSTArrayEraseUnordered2.h"

void BSTArrayEraseUnordered2::Op6640d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op664130(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6c25e0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6c2640(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6c26a0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6c2700(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6c2760(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6c27c0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6c2820(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6c2880(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6c28e0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6c2940(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6c78f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6d1d70(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6d1dd0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6d1e30(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6dbac0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op6dbb20(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op736ba0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op73bce0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op73bd40(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op772320(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op772380(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op7723e0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op772440(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op7724a0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op772500(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op772560(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op7725c0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered2::Op772620(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

