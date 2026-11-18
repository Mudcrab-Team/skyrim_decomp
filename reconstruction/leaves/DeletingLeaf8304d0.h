// Source exposure: binary-analysis
// DeletingLeaf8304d0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8304d0 {
public:
    virtual ~DeletingLeaf8304d0() {}
};
static_assert(sizeof(DeletingLeaf8304d0) == 8, "minimal virtual interface size");
