// Source exposure: binary-analysis
// DeletingLeaf4f9fc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4f9fc0 {
public:
    virtual ~DeletingLeaf4f9fc0() {}
};
static_assert(sizeof(DeletingLeaf4f9fc0) == 8, "minimal virtual interface size");
