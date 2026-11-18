// Source exposure: binary-analysis
// DeletingLeaf7a7e60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7a7e60 {
public:
    virtual ~DeletingLeaf7a7e60() {}
};
static_assert(sizeof(DeletingLeaf7a7e60) == 8, "minimal virtual interface size");
