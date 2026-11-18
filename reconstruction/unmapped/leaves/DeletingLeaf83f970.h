// Source exposure: binary-analysis
// DeletingLeaf83f970, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83f970 {
public:
    virtual ~DeletingLeaf83f970() {}
};
static_assert(sizeof(DeletingLeaf83f970) == 8, "minimal virtual interface size");
