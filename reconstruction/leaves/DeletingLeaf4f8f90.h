// Source exposure: binary-analysis
// DeletingLeaf4f8f90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4f8f90 {
public:
    virtual ~DeletingLeaf4f8f90() {}
};
static_assert(sizeof(DeletingLeaf4f8f90) == 8, "minimal virtual interface size");
