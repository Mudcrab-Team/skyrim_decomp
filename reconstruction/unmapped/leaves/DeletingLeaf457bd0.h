// Source exposure: binary-analysis
// DeletingLeaf457bd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457bd0 {
public:
    virtual ~DeletingLeaf457bd0() {}
};
static_assert(sizeof(DeletingLeaf457bd0) == 8, "minimal virtual interface size");
