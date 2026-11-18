// Source exposure: binary-analysis
// DeletingLeaf83dad0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83dad0 {
public:
    virtual ~DeletingLeaf83dad0() {}
};
static_assert(sizeof(DeletingLeaf83dad0) == 8, "minimal virtual interface size");
