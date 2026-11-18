// Source exposure: binary-analysis
// DeletingLeaf8aeb40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8aeb40 {
public:
    virtual ~DeletingLeaf8aeb40() {}
};
static_assert(sizeof(DeletingLeaf8aeb40) == 8, "minimal virtual interface size");
