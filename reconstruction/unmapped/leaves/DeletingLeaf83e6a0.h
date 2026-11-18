// Source exposure: binary-analysis
// DeletingLeaf83e6a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83e6a0 {
public:
    virtual ~DeletingLeaf83e6a0() {}
};
static_assert(sizeof(DeletingLeaf83e6a0) == 8, "minimal virtual interface size");
