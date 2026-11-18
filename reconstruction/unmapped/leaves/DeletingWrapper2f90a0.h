// Source exposure: binary-analysis
// DeletingWrapper2f90a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper2f90a0 {
public:
    virtual ~DeletingWrapper2f90a0();
};
static_assert(sizeof(DeletingWrapper2f90a0) == 8, "interface layout");
