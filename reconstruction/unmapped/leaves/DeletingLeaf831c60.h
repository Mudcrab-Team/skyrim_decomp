// Source exposure: binary-analysis
// DeletingLeaf831c60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831c60 {
public:
    virtual ~DeletingLeaf831c60() {}
};
static_assert(sizeof(DeletingLeaf831c60) == 8, "minimal virtual interface size");
