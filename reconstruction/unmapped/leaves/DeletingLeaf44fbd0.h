// Source exposure: binary-analysis
// DeletingLeaf44fbd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf44fbd0 {
public:
    virtual ~DeletingLeaf44fbd0() {}
};
static_assert(sizeof(DeletingLeaf44fbd0) == 8, "minimal virtual interface size");
