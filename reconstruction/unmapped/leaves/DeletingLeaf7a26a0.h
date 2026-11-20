// Source exposure: binary-analysis
// DeletingLeaf7a26a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7a26a0 {
public:
    virtual ~DeletingLeaf7a26a0() {}
};
static_assert(sizeof(DeletingLeaf7a26a0) == 8, "minimal virtual interface size");
