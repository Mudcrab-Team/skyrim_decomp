// Source exposure: binary-analysis
// DeletingLeaf122c4d0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122c4d0 {
public:
    virtual ~DeletingLeaf122c4d0() {}
};
static_assert(sizeof(DeletingLeaf122c4d0) == 8, "minimal virtual interface size");
