// Source exposure: binary-analysis
// DeletingLeaf2d3990, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf2d3990 {
public:
    virtual ~DeletingLeaf2d3990() {}
};
static_assert(sizeof(DeletingLeaf2d3990) == 8, "minimal virtual interface size");
