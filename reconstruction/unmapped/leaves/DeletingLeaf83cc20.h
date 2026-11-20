// Source exposure: binary-analysis
// DeletingLeaf83cc20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83cc20 {
public:
    virtual ~DeletingLeaf83cc20() {}
};
static_assert(sizeof(DeletingLeaf83cc20) == 8, "minimal virtual interface size");
