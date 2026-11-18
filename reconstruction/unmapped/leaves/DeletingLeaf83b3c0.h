// Source exposure: binary-analysis
// DeletingLeaf83b3c0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83b3c0 {
public:
    virtual ~DeletingLeaf83b3c0() {}
};
static_assert(sizeof(DeletingLeaf83b3c0) == 8, "minimal virtual interface size");
