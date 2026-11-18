// Source exposure: binary-analysis
// DeletingLeaf8ec970, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8ec970 {
public:
    virtual ~DeletingLeaf8ec970() {}
};
static_assert(sizeof(DeletingLeaf8ec970) == 8, "minimal virtual interface size");
