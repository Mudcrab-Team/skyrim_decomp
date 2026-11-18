// Source exposure: binary-analysis
// DeletingLeaf816830, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf816830 {
public:
    virtual ~DeletingLeaf816830() {}
};
static_assert(sizeof(DeletingLeaf816830) == 8, "minimal virtual interface size");
