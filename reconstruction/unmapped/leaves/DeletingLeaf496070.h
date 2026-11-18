// Source exposure: binary-analysis
// DeletingLeaf496070, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf496070 {
public:
    virtual ~DeletingLeaf496070() {}
};
static_assert(sizeof(DeletingLeaf496070) == 8, "minimal virtual interface size");
