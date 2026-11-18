// Source exposure: binary-analysis
// DeletingLeaf849970, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf849970 {
public:
    virtual ~DeletingLeaf849970() {}
};
static_assert(sizeof(DeletingLeaf849970) == 8, "minimal virtual interface size");
