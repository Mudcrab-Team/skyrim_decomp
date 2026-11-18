// Source exposure: binary-analysis
// DeletingLeaf44fdd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf44fdd0 {
public:
    virtual ~DeletingLeaf44fdd0() {}
};
static_assert(sizeof(DeletingLeaf44fdd0) == 8, "minimal virtual interface size");
