// Source exposure: binary-analysis
// DeletingLeaf5eaef0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf5eaef0 {
public:
    virtual ~DeletingLeaf5eaef0() {}
};
static_assert(sizeof(DeletingLeaf5eaef0) == 8, "minimal virtual interface size");
