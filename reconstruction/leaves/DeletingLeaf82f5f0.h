// Source exposure: binary-analysis
// DeletingLeaf82f5f0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf82f5f0 {
public:
    virtual ~DeletingLeaf82f5f0() {}
};
static_assert(sizeof(DeletingLeaf82f5f0) == 8, "minimal virtual interface size");
