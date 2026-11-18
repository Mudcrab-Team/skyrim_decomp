// Source exposure: binary-analysis
// DeletingLeaf5beca0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf5beca0 {
public:
    virtual ~DeletingLeaf5beca0() {}
};
static_assert(sizeof(DeletingLeaf5beca0) == 8, "minimal virtual interface size");
