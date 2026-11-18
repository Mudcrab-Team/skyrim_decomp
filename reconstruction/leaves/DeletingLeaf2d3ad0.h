// Source exposure: binary-analysis
// DeletingLeaf2d3ad0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf2d3ad0 {
public:
    virtual ~DeletingLeaf2d3ad0() {}
};
static_assert(sizeof(DeletingLeaf2d3ad0) == 8, "minimal virtual interface size");
