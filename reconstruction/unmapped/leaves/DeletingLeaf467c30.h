// Source exposure: binary-analysis
// DeletingLeaf467c30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf467c30 {
public:
    virtual ~DeletingLeaf467c30() {}
};
static_assert(sizeof(DeletingLeaf467c30) == 8, "minimal virtual interface size");
