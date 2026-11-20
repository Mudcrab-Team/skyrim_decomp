// Source exposure: binary-analysis
// DeletingLeaf831f90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831f90 {
public:
    virtual ~DeletingLeaf831f90() {}
};
static_assert(sizeof(DeletingLeaf831f90) == 8, "minimal virtual interface size");
