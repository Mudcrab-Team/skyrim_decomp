// Source exposure: binary-analysis
// DeletingLeaf1e7840, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1e7840 {
public:
    virtual ~DeletingLeaf1e7840() {}
};
static_assert(sizeof(DeletingLeaf1e7840) == 8, "minimal virtual interface size");
