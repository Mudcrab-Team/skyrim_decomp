// Source exposure: binary-analysis
// DeletingLeaf831fc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831fc0 {
public:
    virtual ~DeletingLeaf831fc0() {}
};
static_assert(sizeof(DeletingLeaf831fc0) == 8, "minimal virtual interface size");
