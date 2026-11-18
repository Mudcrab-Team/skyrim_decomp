// Source exposure: binary-analysis
// DeletingLeaf8d5470, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8d5470 {
public:
    virtual ~DeletingLeaf8d5470() {}
};
static_assert(sizeof(DeletingLeaf8d5470) == 8, "minimal virtual interface size");
