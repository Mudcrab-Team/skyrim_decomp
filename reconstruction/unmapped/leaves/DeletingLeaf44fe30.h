// Source exposure: binary-analysis
// DeletingLeaf44fe30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf44fe30 {
public:
    virtual ~DeletingLeaf44fe30() {}
};
static_assert(sizeof(DeletingLeaf44fe30) == 8, "minimal virtual interface size");
