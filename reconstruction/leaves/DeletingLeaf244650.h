// Source exposure: binary-analysis
// DeletingLeaf244650, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf244650 {
public:
    virtual ~DeletingLeaf244650() {}
};
static_assert(sizeof(DeletingLeaf244650) == 8, "minimal virtual interface size");
