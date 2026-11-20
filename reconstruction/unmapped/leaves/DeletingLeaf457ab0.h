// Source exposure: binary-analysis
// DeletingLeaf457ab0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457ab0 {
public:
    virtual ~DeletingLeaf457ab0() {}
};
static_assert(sizeof(DeletingLeaf457ab0) == 8, "minimal virtual interface size");
