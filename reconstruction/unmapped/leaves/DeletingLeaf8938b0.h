// Source exposure: binary-analysis
// DeletingLeaf8938b0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8938b0 {
public:
    virtual ~DeletingLeaf8938b0() {}
};
static_assert(sizeof(DeletingLeaf8938b0) == 8, "minimal virtual interface size");
