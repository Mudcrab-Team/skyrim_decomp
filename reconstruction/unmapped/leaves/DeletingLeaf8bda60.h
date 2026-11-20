// Source exposure: binary-analysis
// DeletingLeaf8bda60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8bda60 {
public:
    virtual ~DeletingLeaf8bda60() {}
};
static_assert(sizeof(DeletingLeaf8bda60) == 8, "minimal virtual interface size");
