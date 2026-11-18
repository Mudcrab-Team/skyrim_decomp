// Source exposure: binary-analysis
// DeletingLeaf457ba0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457ba0 {
public:
    virtual ~DeletingLeaf457ba0() {}
};
static_assert(sizeof(DeletingLeaf457ba0) == 8, "minimal virtual interface size");
