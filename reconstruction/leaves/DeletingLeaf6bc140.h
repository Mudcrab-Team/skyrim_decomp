// Source exposure: binary-analysis
// DeletingLeaf6bc140, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf6bc140 {
public:
    virtual ~DeletingLeaf6bc140() {}
};
static_assert(sizeof(DeletingLeaf6bc140) == 8, "minimal virtual interface size");
