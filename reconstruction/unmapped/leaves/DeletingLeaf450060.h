// Source exposure: binary-analysis
// DeletingLeaf450060, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf450060 {
public:
    virtual ~DeletingLeaf450060() {}
};
static_assert(sizeof(DeletingLeaf450060) == 8, "minimal virtual interface size");
