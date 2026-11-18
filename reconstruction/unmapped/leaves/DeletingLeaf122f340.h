// Source exposure: binary-analysis
// DeletingLeaf122f340, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122f340 {
public:
    virtual ~DeletingLeaf122f340() {}
};
static_assert(sizeof(DeletingLeaf122f340) == 8, "minimal virtual interface size");
