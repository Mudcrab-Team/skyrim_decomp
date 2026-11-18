// Source exposure: binary-analysis
// DeletingLeaf11d3010, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11d3010 {
public:
    virtual ~DeletingLeaf11d3010() {}
};
static_assert(sizeof(DeletingLeaf11d3010) == 8, "minimal virtual interface size");
