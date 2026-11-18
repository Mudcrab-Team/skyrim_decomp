// Source exposure: binary-analysis
// DeletingLeaf474660, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf474660 {
public:
    virtual ~DeletingLeaf474660() {}
};
static_assert(sizeof(DeletingLeaf474660) == 8, "minimal virtual interface size");
