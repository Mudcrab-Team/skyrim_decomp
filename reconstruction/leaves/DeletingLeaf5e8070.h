// Source exposure: binary-analysis
// DeletingLeaf5e8070, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf5e8070 {
public:
    virtual ~DeletingLeaf5e8070() {}
};
static_assert(sizeof(DeletingLeaf5e8070) == 8, "minimal virtual interface size");
