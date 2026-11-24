// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseUnordered3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x772680 BSTArrayEraseUnordered3::Op772680
// 0x7726e0 BSTArrayEraseUnordered3::Op7726e0
// 0x772740 BSTArrayEraseUnordered3::Op772740
// 0x7727a0 BSTArrayEraseUnordered3::Op7727a0
// 0x772800 BSTArrayEraseUnordered3::Op772800
// 0x772860 BSTArrayEraseUnordered3::Op772860
// 0x7728c0 BSTArrayEraseUnordered3::Op7728c0
// 0x772920 BSTArrayEraseUnordered3::Op772920
// 0x78c360 BSTArrayEraseUnordered3::Op78c360
// 0x7b4c50 BSTArrayEraseUnordered3::Op7b4c50
// 0x7b4cb0 BSTArrayEraseUnordered3::Op7b4cb0
// 0x7c3840 BSTArrayEraseUnordered3::Op7c3840
// 0x805730 BSTArrayEraseUnordered3::Op805730
// 0x905c10 BSTArrayEraseUnordered3::Op905c10
// 0x915b60 BSTArrayEraseUnordered3::Op915b60
// 0x915bc0 BSTArrayEraseUnordered3::Op915bc0
// 0x924ec0 BSTArrayEraseUnordered3::Op924ec0
// 0x93ce10 BSTArrayEraseUnordered3::Op93ce10
// 0x946da0 BSTArrayEraseUnordered3::Op946da0
// 0x950e10 BSTArrayEraseUnordered3::Op950e10
// 0x974660 BSTArrayEraseUnordered3::Op974660
// 0x975db0 BSTArrayEraseUnordered3::Op975db0
// 0x9869d0 BSTArrayEraseUnordered3::Op9869d0
// 0x9c3010 BSTArrayEraseUnordered3::Op9c3010
// 0x9cc850 BSTArrayEraseUnordered3::Op9cc850
// 0x9cc8b0 BSTArrayEraseUnordered3::Op9cc8b0
// 0x9f6470 BSTArrayEraseUnordered3::Op9f6470
// 0x9f64d0 BSTArrayEraseUnordered3::Op9f64d0
// 0x9f6530 BSTArrayEraseUnordered3::Op9f6530
// 0x9f6590 BSTArrayEraseUnordered3::Op9f6590
#include "BSTArrayEraseUnordered3.h"

void BSTArrayEraseUnordered3::Op772680(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op7726e0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op772740(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op7727a0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op772800(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op772860(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op7728c0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op772920(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op78c360(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 4u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op7b4c50(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op7b4cb0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op7c3840(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op805730(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op905c10(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op915b60(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op915bc0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op924ec0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op93ce10(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op946da0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op950e10(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op974660(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op975db0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op9869d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op9c3010(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op9cc850(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op9cc8b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op9f6470(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op9f64d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op9f6530(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered3::Op9f6590(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

