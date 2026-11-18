// Source exposure: binary-analysis
// DeletingLeaf893c30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf893c30 {
public:
    virtual ~DeletingLeaf893c30() {}
};
static_assert(sizeof(DeletingLeaf893c30) == 8, "minimal virtual interface size");
