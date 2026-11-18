// Source exposure: binary-analysis
// DeletingLeaf121acc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121acc0 {
public:
    virtual ~DeletingLeaf121acc0() {}
};
static_assert(sizeof(DeletingLeaf121acc0) == 8, "minimal virtual interface size");
