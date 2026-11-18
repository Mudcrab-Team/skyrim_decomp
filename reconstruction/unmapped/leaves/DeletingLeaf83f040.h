// Source exposure: binary-analysis
// DeletingLeaf83f040, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83f040 {
public:
    virtual ~DeletingLeaf83f040() {}
};
static_assert(sizeof(DeletingLeaf83f040) == 8, "minimal virtual interface size");
