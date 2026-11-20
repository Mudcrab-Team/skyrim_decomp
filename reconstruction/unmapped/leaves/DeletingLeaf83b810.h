// Source exposure: binary-analysis
// DeletingLeaf83b810, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83b810 {
public:
    virtual ~DeletingLeaf83b810() {}
};
static_assert(sizeof(DeletingLeaf83b810) == 8, "minimal virtual interface size");
