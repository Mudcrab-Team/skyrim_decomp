// Source exposure: binary-analysis
// DeletingLeaf457990, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457990 {
public:
    virtual ~DeletingLeaf457990() {}
};
static_assert(sizeof(DeletingLeaf457990) == 8, "minimal virtual interface size");
