// Source exposure: binary-analysis
// DeletingLeaf384aa0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf384aa0 {
public:
    virtual ~DeletingLeaf384aa0() {}
};
static_assert(sizeof(DeletingLeaf384aa0) == 8, "minimal virtual interface size");
