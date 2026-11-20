// Source exposure: binary-analysis
// DeletingLeaf457810, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457810 {
public:
    virtual ~DeletingLeaf457810() {}
};
static_assert(sizeof(DeletingLeaf457810) == 8, "minimal virtual interface size");
