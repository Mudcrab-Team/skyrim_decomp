// Source exposure: binary-analysis
// DeletingLeaf122ce30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122ce30 {
public:
    virtual ~DeletingLeaf122ce30() {}
};
static_assert(sizeof(DeletingLeaf122ce30) == 8, "minimal virtual interface size");
