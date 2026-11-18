// Source exposure: binary-analysis
// DeletingLeaf9efd50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9efd50 {
public:
    virtual ~DeletingLeaf9efd50() {}
};
static_assert(sizeof(DeletingLeaf9efd50) == 8, "minimal virtual interface size");
