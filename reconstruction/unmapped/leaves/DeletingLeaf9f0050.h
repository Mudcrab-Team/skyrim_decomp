// Source exposure: binary-analysis
// DeletingLeaf9f0050, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9f0050 {
public:
    virtual ~DeletingLeaf9f0050() {}
};
static_assert(sizeof(DeletingLeaf9f0050) == 8, "minimal virtual interface size");
