// Source exposure: binary-analysis
// DeletingLeaf842da0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf842da0 {
public:
    virtual ~DeletingLeaf842da0() {}
};
static_assert(sizeof(DeletingLeaf842da0) == 8, "minimal virtual interface size");
