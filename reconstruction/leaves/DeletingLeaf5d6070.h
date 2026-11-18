// Source exposure: binary-analysis
// DeletingLeaf5d6070, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf5d6070 {
public:
    virtual ~DeletingLeaf5d6070() {}
};
static_assert(sizeof(DeletingLeaf5d6070) == 8, "minimal virtual interface size");
