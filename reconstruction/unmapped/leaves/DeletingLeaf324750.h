// Source exposure: binary-analysis
// DeletingLeaf324750, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf324750 {
public:
    virtual ~DeletingLeaf324750() {}
};
static_assert(sizeof(DeletingLeaf324750) == 8, "minimal virtual interface size");
