// Source exposure: binary-analysis
// DeletingLeaf8a41c0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8a41c0 {
public:
    virtual ~DeletingLeaf8a41c0() {}
};
static_assert(sizeof(DeletingLeaf8a41c0) == 8, "minimal virtual interface size");
