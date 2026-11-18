// Source exposure: binary-analysis
// DeletingLeaf78fac0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf78fac0 {
public:
    virtual ~DeletingLeaf78fac0() {}
};
static_assert(sizeof(DeletingLeaf78fac0) == 8, "minimal virtual interface size");
