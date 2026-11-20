// Source exposure: binary-analysis
// DeletingLeaf8ea310, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8ea310 {
public:
    virtual ~DeletingLeaf8ea310() {}
};
static_assert(sizeof(DeletingLeaf8ea310) == 8, "minimal virtual interface size");
