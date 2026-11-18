// Source exposure: binary-analysis
// DeletingLeaf83f610, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83f610 {
public:
    virtual ~DeletingLeaf83f610() {}
};
static_assert(sizeof(DeletingLeaf83f610) == 8, "minimal virtual interface size");
