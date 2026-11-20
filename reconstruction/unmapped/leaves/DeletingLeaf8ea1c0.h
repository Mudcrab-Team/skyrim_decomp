// Source exposure: binary-analysis
// DeletingLeaf8ea1c0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8ea1c0 {
public:
    virtual ~DeletingLeaf8ea1c0() {}
};
static_assert(sizeof(DeletingLeaf8ea1c0) == 8, "minimal virtual interface size");
