// Source exposure: binary-analysis
// DeletingLeaf7d0d60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7d0d60 {
public:
    virtual ~DeletingLeaf7d0d60() {}
};
static_assert(sizeof(DeletingLeaf7d0d60) == 8, "minimal virtual interface size");
