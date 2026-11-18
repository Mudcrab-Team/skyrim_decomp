// Source exposure: binary-analysis
// DeletingLeaf122c9b0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122c9b0 {
public:
    virtual ~DeletingLeaf122c9b0() {}
};
static_assert(sizeof(DeletingLeaf122c9b0) == 8, "minimal virtual interface size");
