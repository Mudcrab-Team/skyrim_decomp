// Source exposure: binary-analysis
// DeletingLeaf83e980, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83e980 {
public:
    virtual ~DeletingLeaf83e980() {}
};
static_assert(sizeof(DeletingLeaf83e980) == 8, "minimal virtual interface size");
