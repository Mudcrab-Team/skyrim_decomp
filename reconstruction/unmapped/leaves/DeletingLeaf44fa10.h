// Source exposure: binary-analysis
// DeletingLeaf44fa10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf44fa10 {
public:
    virtual ~DeletingLeaf44fa10() {}
};
static_assert(sizeof(DeletingLeaf44fa10) == 8, "minimal virtual interface size");
