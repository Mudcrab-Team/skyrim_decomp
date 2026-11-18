// Source exposure: binary-analysis
// DeletingLeaf816970, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf816970 {
public:
    virtual ~DeletingLeaf816970() {}
};
static_assert(sizeof(DeletingLeaf816970) == 8, "minimal virtual interface size");
