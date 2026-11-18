// Source exposure: binary-analysis
// DeletingLeaf457f90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457f90 {
public:
    virtual ~DeletingLeaf457f90() {}
};
static_assert(sizeof(DeletingLeaf457f90) == 8, "minimal virtual interface size");
