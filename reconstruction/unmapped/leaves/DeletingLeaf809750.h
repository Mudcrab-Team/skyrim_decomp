// Source exposure: binary-analysis
// DeletingLeaf809750, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf809750 {
public:
    virtual ~DeletingLeaf809750() {}
};
static_assert(sizeof(DeletingLeaf809750) == 8, "minimal virtual interface size");
