// Source exposure: binary-analysis
// DeletingLeaf4d3970, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4d3970 {
public:
    virtual ~DeletingLeaf4d3970() {}
};
static_assert(sizeof(DeletingLeaf4d3970) == 8, "minimal virtual interface size");
