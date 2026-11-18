// Source exposure: binary-analysis
// DeletingLeaf8cbe40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8cbe40 {
public:
    virtual ~DeletingLeaf8cbe40() {}
};
static_assert(sizeof(DeletingLeaf8cbe40) == 8, "minimal virtual interface size");
