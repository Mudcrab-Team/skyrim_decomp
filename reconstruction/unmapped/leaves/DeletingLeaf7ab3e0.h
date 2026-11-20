// Source exposure: binary-analysis
// DeletingLeaf7ab3e0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7ab3e0 {
public:
    virtual ~DeletingLeaf7ab3e0() {}
};
static_assert(sizeof(DeletingLeaf7ab3e0) == 8, "minimal virtual interface size");
