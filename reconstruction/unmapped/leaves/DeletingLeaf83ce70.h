// Source exposure: binary-analysis
// DeletingLeaf83ce70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83ce70 {
public:
    virtual ~DeletingLeaf83ce70() {}
};
static_assert(sizeof(DeletingLeaf83ce70) == 8, "minimal virtual interface size");
