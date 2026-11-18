// Source exposure: binary-analysis
// DeletingLeaf4617b0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4617b0 {
public:
    virtual ~DeletingLeaf4617b0() {}
};
static_assert(sizeof(DeletingLeaf4617b0) == 8, "minimal virtual interface size");
