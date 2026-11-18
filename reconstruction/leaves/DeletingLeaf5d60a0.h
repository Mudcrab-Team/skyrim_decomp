// Source exposure: binary-analysis
// DeletingLeaf5d60a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf5d60a0 {
public:
    virtual ~DeletingLeaf5d60a0() {}
};
static_assert(sizeof(DeletingLeaf5d60a0) == 8, "minimal virtual interface size");
