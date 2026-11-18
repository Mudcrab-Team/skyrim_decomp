// Source exposure: binary-analysis
// DeletingLeaf849ad0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf849ad0 {
public:
    virtual ~DeletingLeaf849ad0() {}
};
static_assert(sizeof(DeletingLeaf849ad0) == 8, "minimal virtual interface size");
