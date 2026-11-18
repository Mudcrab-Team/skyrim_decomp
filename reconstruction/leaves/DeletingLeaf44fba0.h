// Source exposure: binary-analysis
// DeletingLeaf44fba0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf44fba0 {
public:
    virtual ~DeletingLeaf44fba0() {}
};
static_assert(sizeof(DeletingLeaf44fba0) == 8, "minimal virtual interface size");
