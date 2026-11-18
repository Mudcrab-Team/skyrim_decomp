// Source exposure: binary-analysis
// DeletingLeaf122ce60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122ce60 {
public:
    virtual ~DeletingLeaf122ce60() {}
};
static_assert(sizeof(DeletingLeaf122ce60) == 8, "minimal virtual interface size");
