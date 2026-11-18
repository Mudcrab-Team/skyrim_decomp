// Source exposure: binary-analysis
// DeletingLeaf80faa0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf80faa0 {
public:
    virtual ~DeletingLeaf80faa0() {}
};
static_assert(sizeof(DeletingLeaf80faa0) == 8, "minimal virtual interface size");
