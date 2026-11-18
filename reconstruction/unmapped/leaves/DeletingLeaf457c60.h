// Source exposure: binary-analysis
// DeletingLeaf457c60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457c60 {
public:
    virtual ~DeletingLeaf457c60() {}
};
static_assert(sizeof(DeletingLeaf457c60) == 8, "minimal virtual interface size");
