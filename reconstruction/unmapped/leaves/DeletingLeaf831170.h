// Source exposure: binary-analysis
// DeletingLeaf831170, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831170 {
public:
    virtual ~DeletingLeaf831170() {}
};
static_assert(sizeof(DeletingLeaf831170) == 8, "minimal virtual interface size");
