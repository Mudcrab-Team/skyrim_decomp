// Source exposure: binary-analysis
// DeletingLeaf476840, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf476840 {
public:
    virtual ~DeletingLeaf476840() {}
};
static_assert(sizeof(DeletingLeaf476840) == 8, "minimal virtual interface size");
