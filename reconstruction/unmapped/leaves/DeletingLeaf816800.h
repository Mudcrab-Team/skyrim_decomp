// Source exposure: binary-analysis
// DeletingLeaf816800, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf816800 {
public:
    virtual ~DeletingLeaf816800() {}
};
static_assert(sizeof(DeletingLeaf816800) == 8, "minimal virtual interface size");
