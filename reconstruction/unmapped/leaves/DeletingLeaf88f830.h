// Source exposure: binary-analysis
// DeletingLeaf88f830, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf88f830 {
public:
    virtual ~DeletingLeaf88f830() {}
};
static_assert(sizeof(DeletingLeaf88f830) == 8, "minimal virtual interface size");
