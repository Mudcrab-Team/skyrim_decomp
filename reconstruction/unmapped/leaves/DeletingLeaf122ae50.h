// Source exposure: binary-analysis
// DeletingLeaf122ae50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122ae50 {
public:
    virtual ~DeletingLeaf122ae50() {}
};
static_assert(sizeof(DeletingLeaf122ae50) == 8, "minimal virtual interface size");
