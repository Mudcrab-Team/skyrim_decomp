// Source exposure: binary-analysis
// DeletingLeaf5becd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf5becd0 {
public:
    virtual ~DeletingLeaf5becd0() {}
};
static_assert(sizeof(DeletingLeaf5becd0) == 8, "minimal virtual interface size");
