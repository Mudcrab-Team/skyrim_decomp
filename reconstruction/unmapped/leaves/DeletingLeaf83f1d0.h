// Source exposure: binary-analysis
// DeletingLeaf83f1d0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83f1d0 {
public:
    virtual ~DeletingLeaf83f1d0() {}
};
static_assert(sizeof(DeletingLeaf83f1d0) == 8, "minimal virtual interface size");
