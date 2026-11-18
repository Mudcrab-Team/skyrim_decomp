// Source exposure: binary-analysis
// DeletingLeaf8cc040, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8cc040 {
public:
    virtual ~DeletingLeaf8cc040() {}
};
static_assert(sizeof(DeletingLeaf8cc040) == 8, "minimal virtual interface size");
