// Source exposure: binary-analysis
// DeletingLeaf8bdc30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8bdc30 {
public:
    virtual ~DeletingLeaf8bdc30() {}
};
static_assert(sizeof(DeletingLeaf8bdc30) == 8, "minimal virtual interface size");
