// Source exposure: binary-analysis
// DeletingLeaf478f60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf478f60 {
public:
    virtual ~DeletingLeaf478f60() {}
};
static_assert(sizeof(DeletingLeaf478f60) == 8, "minimal virtual interface size");
