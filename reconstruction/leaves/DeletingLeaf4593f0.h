// Source exposure: binary-analysis
// DeletingLeaf4593f0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4593f0 {
public:
    virtual ~DeletingLeaf4593f0() {}
};
static_assert(sizeof(DeletingLeaf4593f0) == 8, "minimal virtual interface size");
