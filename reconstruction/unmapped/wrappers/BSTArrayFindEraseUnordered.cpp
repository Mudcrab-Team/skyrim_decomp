// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayFindEraseUnordered, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x17ac40 BSTArrayFindEraseUnordered::Op17ac40
// 0x17ace0 BSTArrayFindEraseUnordered::Op17ace0
// 0x32a930 BSTArrayFindEraseUnordered::Op32a930
// 0x32a9d0 BSTArrayFindEraseUnordered::Op32a9d0
// 0x4d1ea0 BSTArrayFindEraseUnordered::Op4d1ea0
// 0x4d1f40 BSTArrayFindEraseUnordered::Op4d1f40
#include "BSTArrayFindEraseUnordered.h"

bool BSTArrayFindEraseUnordered::Op17ac40(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        std::uint32_t tail = size - found - 1u;
        std::uint32_t moveCount = (tail < 1u) ? tail : 1u;
        ArrayMove_ce0980(&self->size, self->data, found, size - moveCount, moveCount, 8u);
        --self->size;
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseUnordered::Op17ace0(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        std::uint32_t tail = size - found - 1u;
        std::uint32_t moveCount = (tail < 1u) ? tail : 1u;
        ArrayMove_ce0980(&self->size, self->data, found, size - moveCount, moveCount, 8u);
        --self->size;
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseUnordered::Op32a930(BSTArrayHeap* self, const std::uint32_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint32_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        std::uint32_t tail = size - found - 1u;
        std::uint32_t moveCount = (tail < 1u) ? tail : 1u;
        ArrayMove_ce0980(&self->size, self->data, found, size - moveCount, moveCount, 4u);
        --self->size;
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseUnordered::Op32a9d0(BSTArrayHeap* self, const std::uint32_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint32_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        std::uint32_t tail = size - found - 1u;
        std::uint32_t moveCount = (tail < 1u) ? tail : 1u;
        ArrayMove_ce0980(&self->size, self->data, found, size - moveCount, moveCount, 4u);
        --self->size;
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseUnordered::Op4d1ea0(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        std::uint32_t tail = size - found - 1u;
        std::uint32_t moveCount = (tail < 1u) ? tail : 1u;
        ArrayMove_ce0980(&self->size, self->data, found, size - moveCount, moveCount, 8u);
        --self->size;
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseUnordered::Op4d1f40(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        std::uint32_t tail = size - found - 1u;
        std::uint32_t moveCount = (tail < 1u) ? tail : 1u;
        ArrayMove_ce0980(&self->size, self->data, found, size - moveCount, moveCount, 8u);
        --self->size;
    }
    return found != 0xFFFFFFFFu;
}

