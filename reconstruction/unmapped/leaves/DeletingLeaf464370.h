// Source exposure: binary-analysis
// DeletingLeaf464370, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf464370 {
public:
    virtual ~DeletingLeaf464370() {}
};
static_assert(sizeof(DeletingLeaf464370) == 8, "minimal virtual interface size");
