// Source exposure: binary-analysis
// DeletingLeaf9a33b0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9a33b0 {
public:
    virtual ~DeletingLeaf9a33b0() {}
};
static_assert(sizeof(DeletingLeaf9a33b0) == 8, "minimal virtual interface size");
