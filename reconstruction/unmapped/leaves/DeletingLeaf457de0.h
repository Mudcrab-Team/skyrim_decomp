// Source exposure: binary-analysis
// DeletingLeaf457de0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457de0 {
public:
    virtual ~DeletingLeaf457de0() {}
};
static_assert(sizeof(DeletingLeaf457de0) == 8, "minimal virtual interface size");
