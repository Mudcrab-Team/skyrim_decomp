// Source exposure: binary-analysis
// DeletingLeaf83b7b0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83b7b0 {
public:
    virtual ~DeletingLeaf83b7b0() {}
};
static_assert(sizeof(DeletingLeaf83b7b0) == 8, "minimal virtual interface size");
