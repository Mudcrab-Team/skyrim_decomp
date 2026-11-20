// Source exposure: binary-analysis
// DeletingLeaf8cc070, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8cc070 {
public:
    virtual ~DeletingLeaf8cc070() {}
};
static_assert(sizeof(DeletingLeaf8cc070) == 8, "minimal virtual interface size");
