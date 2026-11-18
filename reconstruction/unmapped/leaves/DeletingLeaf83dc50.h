// Source exposure: binary-analysis
// DeletingLeaf83dc50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83dc50 {
public:
    virtual ~DeletingLeaf83dc50() {}
};
static_assert(sizeof(DeletingLeaf83dc50) == 8, "minimal virtual interface size");
