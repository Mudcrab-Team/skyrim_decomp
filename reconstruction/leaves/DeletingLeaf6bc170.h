// Source exposure: binary-analysis
// DeletingLeaf6bc170, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf6bc170 {
public:
    virtual ~DeletingLeaf6bc170() {}
};
static_assert(sizeof(DeletingLeaf6bc170) == 8, "minimal virtual interface size");
