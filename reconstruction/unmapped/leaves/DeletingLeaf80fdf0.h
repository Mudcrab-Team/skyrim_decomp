// Source exposure: binary-analysis
// DeletingLeaf80fdf0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf80fdf0 {
public:
    virtual ~DeletingLeaf80fdf0() {}
};
static_assert(sizeof(DeletingLeaf80fdf0) == 8, "minimal virtual interface size");
