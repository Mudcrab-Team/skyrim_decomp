// Source exposure: binary-analysis
// DeletingLeaf12374e0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf12374e0 {
public:
    virtual ~DeletingLeaf12374e0() {}
};
static_assert(sizeof(DeletingLeaf12374e0) == 8, "minimal virtual interface size");
