// Source exposure: binary-analysis
// DeletingLeaf90d050, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf90d050 {
public:
    virtual ~DeletingLeaf90d050() {}
};
static_assert(sizeof(DeletingLeaf90d050) == 8, "minimal virtual interface size");
