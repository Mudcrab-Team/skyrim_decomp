// Source exposure: binary-analysis
// DeletingLeaf457840, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457840 {
public:
    virtual ~DeletingLeaf457840() {}
};
static_assert(sizeof(DeletingLeaf457840) == 8, "minimal virtual interface size");
