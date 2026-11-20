// Source exposure: binary-analysis
// DeletingLeaf83c4f0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83c4f0 {
public:
    virtual ~DeletingLeaf83c4f0() {}
};
static_assert(sizeof(DeletingLeaf83c4f0) == 8, "minimal virtual interface size");
