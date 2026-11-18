// Source exposure: binary-analysis
// DeletingLeaf457870, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457870 {
public:
    virtual ~DeletingLeaf457870() {}
};
static_assert(sizeof(DeletingLeaf457870) == 8, "minimal virtual interface size");
