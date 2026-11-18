// Source exposure: binary-analysis
// DeletingLeaf809e30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf809e30 {
public:
    virtual ~DeletingLeaf809e30() {}
};
static_assert(sizeof(DeletingLeaf809e30) == 8, "minimal virtual interface size");
