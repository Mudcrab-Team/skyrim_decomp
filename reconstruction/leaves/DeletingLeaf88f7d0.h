// Source exposure: binary-analysis
// DeletingLeaf88f7d0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf88f7d0 {
public:
    virtual ~DeletingLeaf88f7d0() {}
};
static_assert(sizeof(DeletingLeaf88f7d0) == 8, "minimal virtual interface size");
