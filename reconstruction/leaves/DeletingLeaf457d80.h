// Source exposure: binary-analysis
// DeletingLeaf457d80, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457d80 {
public:
    virtual ~DeletingLeaf457d80() {}
};
static_assert(sizeof(DeletingLeaf457d80) == 8, "minimal virtual interface size");
