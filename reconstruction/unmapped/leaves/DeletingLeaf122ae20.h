// Source exposure: binary-analysis
// DeletingLeaf122ae20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122ae20 {
public:
    virtual ~DeletingLeaf122ae20() {}
};
static_assert(sizeof(DeletingLeaf122ae20) == 8, "minimal virtual interface size");
