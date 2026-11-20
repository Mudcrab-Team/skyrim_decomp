// Source exposure: binary-analysis
// DeletingLeaf8bd760, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8bd760 {
public:
    virtual ~DeletingLeaf8bd760() {}
};
static_assert(sizeof(DeletingLeaf8bd760) == 8, "minimal virtual interface size");
