// Source exposure: binary-analysis
// DeletingLeaf457750, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457750 {
public:
    virtual ~DeletingLeaf457750() {}
};
static_assert(sizeof(DeletingLeaf457750) == 8, "minimal virtual interface size");
