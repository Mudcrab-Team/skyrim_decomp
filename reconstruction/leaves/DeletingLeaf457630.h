// Source exposure: binary-analysis
// DeletingLeaf457630, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457630 {
public:
    virtual ~DeletingLeaf457630() {}
};
static_assert(sizeof(DeletingLeaf457630) == 8, "minimal virtual interface size");
