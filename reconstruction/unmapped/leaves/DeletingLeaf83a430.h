// Source exposure: binary-analysis
// DeletingLeaf83a430, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83a430 {
public:
    virtual ~DeletingLeaf83a430() {}
};
static_assert(sizeof(DeletingLeaf83a430) == 8, "minimal virtual interface size");
