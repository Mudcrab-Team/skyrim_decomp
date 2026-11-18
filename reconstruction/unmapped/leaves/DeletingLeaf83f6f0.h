// Source exposure: binary-analysis
// DeletingLeaf83f6f0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83f6f0 {
public:
    virtual ~DeletingLeaf83f6f0() {}
};
static_assert(sizeof(DeletingLeaf83f6f0) == 8, "minimal virtual interface size");
