// Source exposure: binary-analysis
// DeletingLeaf7ab350, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7ab350 {
public:
    virtual ~DeletingLeaf7ab350() {}
};
static_assert(sizeof(DeletingLeaf7ab350) == 8, "minimal virtual interface size");
