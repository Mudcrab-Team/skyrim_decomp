// Source exposure: binary-analysis
// DeletingLeaf502cb0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf502cb0 {
public:
    virtual ~DeletingLeaf502cb0() {}
};
static_assert(sizeof(DeletingLeaf502cb0) == 8, "minimal virtual interface size");
