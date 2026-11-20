// Source exposure: binary-analysis
// DeletingLeaf848840, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf848840 {
public:
    virtual ~DeletingLeaf848840() {}
};
static_assert(sizeof(DeletingLeaf848840) == 8, "minimal virtual interface size");
