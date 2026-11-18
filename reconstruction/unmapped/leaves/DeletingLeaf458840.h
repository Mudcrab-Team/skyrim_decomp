// Source exposure: binary-analysis
// DeletingLeaf458840, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458840 {
public:
    virtual ~DeletingLeaf458840() {}
};
static_assert(sizeof(DeletingLeaf458840) == 8, "minimal virtual interface size");
