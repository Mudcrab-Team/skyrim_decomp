// Source exposure: binary-analysis
// DeletingLeaf457930, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457930 {
public:
    virtual ~DeletingLeaf457930() {}
};
static_assert(sizeof(DeletingLeaf457930) == 8, "minimal virtual interface size");
