// Source exposure: binary-analysis
// DeletingLeaf83cc90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83cc90 {
public:
    virtual ~DeletingLeaf83cc90() {}
};
static_assert(sizeof(DeletingLeaf83cc90) == 8, "minimal virtual interface size");
