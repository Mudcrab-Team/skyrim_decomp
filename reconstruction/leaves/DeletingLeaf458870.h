// Source exposure: binary-analysis
// DeletingLeaf458870, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458870 {
public:
    virtual ~DeletingLeaf458870() {}
};
static_assert(sizeof(DeletingLeaf458870) == 8, "minimal virtual interface size");
