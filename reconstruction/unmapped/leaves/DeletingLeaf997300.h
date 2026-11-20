// Source exposure: binary-analysis
// DeletingLeaf997300, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf997300 {
public:
    virtual ~DeletingLeaf997300() {}
};
static_assert(sizeof(DeletingLeaf997300) == 8, "minimal virtual interface size");
