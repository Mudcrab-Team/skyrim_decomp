// Source exposure: binary-analysis
// DeletingLeaf9f01a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9f01a0 {
public:
    virtual ~DeletingLeaf9f01a0() {}
};
static_assert(sizeof(DeletingLeaf9f01a0) == 8, "minimal virtual interface size");
