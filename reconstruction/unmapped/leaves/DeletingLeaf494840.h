// Source exposure: binary-analysis
// DeletingLeaf494840, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf494840 {
public:
    virtual ~DeletingLeaf494840() {}
};
static_assert(sizeof(DeletingLeaf494840) == 8, "minimal virtual interface size");
