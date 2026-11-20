// Source exposure: binary-analysis
// DeletingLeaf7d34f0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7d34f0 {
public:
    virtual ~DeletingLeaf7d34f0() {}
};
static_assert(sizeof(DeletingLeaf7d34f0) == 8, "minimal virtual interface size");
