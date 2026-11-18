// Source exposure: binary-analysis
// DeletingLeaf849ef0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf849ef0 {
public:
    virtual ~DeletingLeaf849ef0() {}
};
static_assert(sizeof(DeletingLeaf849ef0) == 8, "minimal virtual interface size");
