// Source exposure: binary-analysis
// DeletingLeaf7d2e90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7d2e90 {
public:
    virtual ~DeletingLeaf7d2e90() {}
};
static_assert(sizeof(DeletingLeaf7d2e90) == 8, "minimal virtual interface size");
