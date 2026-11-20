// Source exposure: binary-analysis
// DeletingLeaf842870, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf842870 {
public:
    virtual ~DeletingLeaf842870() {}
};
static_assert(sizeof(DeletingLeaf842870) == 8, "minimal virtual interface size");
