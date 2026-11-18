// Source exposure: binary-analysis
// DeletingLeaf650980, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf650980 {
public:
    virtual ~DeletingLeaf650980() {}
};
static_assert(sizeof(DeletingLeaf650980) == 8, "minimal virtual interface size");
