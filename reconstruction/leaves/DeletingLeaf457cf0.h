// Source exposure: binary-analysis
// DeletingLeaf457cf0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457cf0 {
public:
    virtual ~DeletingLeaf457cf0() {}
};
static_assert(sizeof(DeletingLeaf457cf0) == 8, "minimal virtual interface size");
