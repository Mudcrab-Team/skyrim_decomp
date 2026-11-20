// Source exposure: binary-analysis
// DeletingLeaf85e210, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf85e210 {
public:
    virtual ~DeletingLeaf85e210() {}
};
static_assert(sizeof(DeletingLeaf85e210) == 8, "minimal virtual interface size");
