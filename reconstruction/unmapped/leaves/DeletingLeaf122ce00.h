// Source exposure: binary-analysis
// DeletingLeaf122ce00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122ce00 {
public:
    virtual ~DeletingLeaf122ce00() {}
};
static_assert(sizeof(DeletingLeaf122ce00) == 8, "minimal virtual interface size");
