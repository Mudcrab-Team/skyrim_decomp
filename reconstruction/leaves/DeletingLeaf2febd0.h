// Source exposure: binary-analysis
// DeletingLeaf2febd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf2febd0 {
public:
    virtual ~DeletingLeaf2febd0() {}
};
static_assert(sizeof(DeletingLeaf2febd0) == 8, "minimal virtual interface size");
