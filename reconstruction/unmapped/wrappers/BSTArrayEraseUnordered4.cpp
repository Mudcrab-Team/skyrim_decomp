// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseUnordered4, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x9f65f0 BSTArrayEraseUnordered4::Op9f65f0
// 0x9f6650 BSTArrayEraseUnordered4::Op9f6650
// 0x9f66b0 BSTArrayEraseUnordered4::Op9f66b0
// 0x9f6710 BSTArrayEraseUnordered4::Op9f6710
// 0x9f6770 BSTArrayEraseUnordered4::Op9f6770
// 0x9f67d0 BSTArrayEraseUnordered4::Op9f67d0
// 0x9f6830 BSTArrayEraseUnordered4::Op9f6830
// 0x9f6890 BSTArrayEraseUnordered4::Op9f6890
// 0x9f68f0 BSTArrayEraseUnordered4::Op9f68f0
// 0x9f6950 BSTArrayEraseUnordered4::Op9f6950
// 0x9f69b0 BSTArrayEraseUnordered4::Op9f69b0
// 0x9f6a10 BSTArrayEraseUnordered4::Op9f6a10
// 0x9f6a70 BSTArrayEraseUnordered4::Op9f6a70
// 0x9f6ad0 BSTArrayEraseUnordered4::Op9f6ad0
// 0x9f6b30 BSTArrayEraseUnordered4::Op9f6b30
// 0x9f6b90 BSTArrayEraseUnordered4::Op9f6b90
// 0x9f6bf0 BSTArrayEraseUnordered4::Op9f6bf0
// 0x9f6c50 BSTArrayEraseUnordered4::Op9f6c50
// 0x9f6cb0 BSTArrayEraseUnordered4::Op9f6cb0
// 0x9f6d10 BSTArrayEraseUnordered4::Op9f6d10
// 0x9f6d70 BSTArrayEraseUnordered4::Op9f6d70
// 0x9f6dd0 BSTArrayEraseUnordered4::Op9f6dd0
// 0x9f6e30 BSTArrayEraseUnordered4::Op9f6e30
// 0x9f6e90 BSTArrayEraseUnordered4::Op9f6e90
// 0x9f6ef0 BSTArrayEraseUnordered4::Op9f6ef0
// 0x9f6f50 BSTArrayEraseUnordered4::Op9f6f50
// 0x9f6fb0 BSTArrayEraseUnordered4::Op9f6fb0
// 0x9f7010 BSTArrayEraseUnordered4::Op9f7010
// 0x9f7070 BSTArrayEraseUnordered4::Op9f7070
// 0x9f70d0 BSTArrayEraseUnordered4::Op9f70d0
#include "BSTArrayEraseUnordered4.h"

void BSTArrayEraseUnordered4::Op9f65f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6650(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f66b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6710(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6770(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f67d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6830(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6890(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f68f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6950(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f69b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6a10(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6a70(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6ad0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6b30(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6b90(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6bf0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6c50(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6cb0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6d10(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6d70(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6dd0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6e30(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6e90(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6ef0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6f50(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f6fb0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f7010(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f7070(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered4::Op9f70d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

