// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayEraseUnordered5, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x9f7130 BSTArrayEraseUnordered5::Op9f7130
// 0x9f7190 BSTArrayEraseUnordered5::Op9f7190
// 0x9f71f0 BSTArrayEraseUnordered5::Op9f71f0
// 0x9f7250 BSTArrayEraseUnordered5::Op9f7250
// 0x9f72b0 BSTArrayEraseUnordered5::Op9f72b0
// 0x9f7310 BSTArrayEraseUnordered5::Op9f7310
// 0x9f7370 BSTArrayEraseUnordered5::Op9f7370
// 0x9f73d0 BSTArrayEraseUnordered5::Op9f73d0
// 0x9f7430 BSTArrayEraseUnordered5::Op9f7430
// 0x9f7490 BSTArrayEraseUnordered5::Op9f7490
// 0xcdf110 BSTArrayEraseUnordered5::Opcdf110
// 0xce2030 BSTArrayEraseUnordered5::Opce2030
// 0xcebae0 BSTArrayEraseUnordered5::Opcebae0
// 0xecca20 BSTArrayEraseUnordered5::Opecca20
// 0xed3610 BSTArrayEraseUnordered5::Oped3610
// 0xed3670 BSTArrayEraseUnordered5::Oped3670
// 0xed36d0 BSTArrayEraseUnordered5::Oped36d0
// 0x14cd210 BSTArrayEraseUnordered5::Op14cd210
// 0x14cd270 BSTArrayEraseUnordered5::Op14cd270
// 0x1596df0 BSTArrayEraseUnordered5::Op1596df0
#include "BSTArrayEraseUnordered5.h"

void BSTArrayEraseUnordered5::Op9f7130(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Op9f7190(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Op9f71f0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Op9f7250(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Op9f72b0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Op9f7310(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Op9f7370(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Op9f73d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Op9f7430(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Op9f7490(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Opcdf110(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Opce2030(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Opcebae0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Opecca20(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Oped3610(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Oped3670(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Oped36d0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Op14cd210(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Op14cd270(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

void BSTArrayEraseUnordered5::Op1596df0(BSTArrayHeap* self, std::uint32_t pos, std::uint32_t count)
{
    std::uint32_t size = self->size;
    std::uint32_t tail = size - pos - count;
    std::uint32_t moveCount = (tail < count) ? tail : count;
    ArrayMove_ce0980(&self->size, self->data, pos, size - moveCount, moveCount, 8u);
    self->size -= count;
}

