// Source exposure: binary-analysis
// DeletingLeaf457d50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457d50 {
public:
    virtual ~DeletingLeaf457d50() {}
};
static_assert(sizeof(DeletingLeaf457d50) == 8, "minimal virtual interface size");
