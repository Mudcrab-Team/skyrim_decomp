// Source exposure: binary-analysis
// DeletingLeaf849aa0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf849aa0 {
public:
    virtual ~DeletingLeaf849aa0() {}
};
static_assert(sizeof(DeletingLeaf849aa0) == 8, "minimal virtual interface size");
