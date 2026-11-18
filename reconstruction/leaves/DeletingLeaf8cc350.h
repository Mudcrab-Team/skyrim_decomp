// Source exposure: binary-analysis
// DeletingLeaf8cc350, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8cc350 {
public:
    virtual ~DeletingLeaf8cc350() {}
};
static_assert(sizeof(DeletingLeaf8cc350) == 8, "minimal virtual interface size");
