// Source exposure: binary-analysis
// DeletingLeaf8aebd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8aebd0 {
public:
    virtual ~DeletingLeaf8aebd0() {}
};
static_assert(sizeof(DeletingLeaf8aebd0) == 8, "minimal virtual interface size");
