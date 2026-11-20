// Source exposure: binary-analysis
// DeletingLeaf475ac0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf475ac0 {
public:
    virtual ~DeletingLeaf475ac0() {}
};
static_assert(sizeof(DeletingLeaf475ac0) == 8, "minimal virtual interface size");
