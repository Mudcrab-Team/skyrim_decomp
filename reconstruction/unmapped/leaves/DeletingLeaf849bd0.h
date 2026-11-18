// Source exposure: binary-analysis
// DeletingLeaf849bd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf849bd0 {
public:
    virtual ~DeletingLeaf849bd0() {}
};
static_assert(sizeof(DeletingLeaf849bd0) == 8, "minimal virtual interface size");
