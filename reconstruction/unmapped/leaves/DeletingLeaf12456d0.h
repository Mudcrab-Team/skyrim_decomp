// Source exposure: binary-analysis
// DeletingLeaf12456d0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf12456d0 {
public:
    virtual ~DeletingLeaf12456d0() {}
};
static_assert(sizeof(DeletingLeaf12456d0) == 8, "minimal virtual interface size");
