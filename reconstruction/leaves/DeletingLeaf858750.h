// Source exposure: binary-analysis
// DeletingLeaf858750, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf858750 {
public:
    virtual ~DeletingLeaf858750() {}
};
static_assert(sizeof(DeletingLeaf858750) == 8, "minimal virtual interface size");
