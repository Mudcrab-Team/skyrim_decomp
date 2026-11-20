// Source exposure: binary-analysis
// DeletingLeaf46d050, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf46d050 {
public:
    virtual ~DeletingLeaf46d050() {}
};
static_assert(sizeof(DeletingLeaf46d050) == 8, "minimal virtual interface size");
