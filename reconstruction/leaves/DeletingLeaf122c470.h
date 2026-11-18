// Source exposure: binary-analysis
// DeletingLeaf122c470, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122c470 {
public:
    virtual ~DeletingLeaf122c470() {}
};
static_assert(sizeof(DeletingLeaf122c470) == 8, "minimal virtual interface size");
