// Source exposure: binary-analysis
// DeletingLeaf122f310, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122f310 {
public:
    virtual ~DeletingLeaf122f310() {}
};
static_assert(sizeof(DeletingLeaf122f310) == 8, "minimal virtual interface size");
