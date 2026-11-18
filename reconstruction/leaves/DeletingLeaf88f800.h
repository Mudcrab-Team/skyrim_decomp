// Source exposure: binary-analysis
// DeletingLeaf88f800, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf88f800 {
public:
    virtual ~DeletingLeaf88f800() {}
};
static_assert(sizeof(DeletingLeaf88f800) == 8, "minimal virtual interface size");
