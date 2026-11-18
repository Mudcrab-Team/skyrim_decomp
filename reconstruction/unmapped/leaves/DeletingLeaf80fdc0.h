// Source exposure: binary-analysis
// DeletingLeaf80fdc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf80fdc0 {
public:
    virtual ~DeletingLeaf80fdc0() {}
};
static_assert(sizeof(DeletingLeaf80fdc0) == 8, "minimal virtual interface size");
