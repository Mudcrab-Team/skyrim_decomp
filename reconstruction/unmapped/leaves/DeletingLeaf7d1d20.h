// Source exposure: binary-analysis
// DeletingLeaf7d1d20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7d1d20 {
public:
    virtual ~DeletingLeaf7d1d20() {}
};
static_assert(sizeof(DeletingLeaf7d1d20) == 8, "minimal virtual interface size");
