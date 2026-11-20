// Source exposure: binary-analysis
// DeletingLeaf831df0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831df0 {
public:
    virtual ~DeletingLeaf831df0() {}
};
static_assert(sizeof(DeletingLeaf831df0) == 8, "minimal virtual interface size");
