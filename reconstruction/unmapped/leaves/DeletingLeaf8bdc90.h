// Source exposure: binary-analysis
// DeletingLeaf8bdc90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8bdc90 {
public:
    virtual ~DeletingLeaf8bdc90() {}
};
static_assert(sizeof(DeletingLeaf8bdc90) == 8, "minimal virtual interface size");
