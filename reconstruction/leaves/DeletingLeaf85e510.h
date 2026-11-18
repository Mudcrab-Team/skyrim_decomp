// Source exposure: binary-analysis
// DeletingLeaf85e510, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf85e510 {
public:
    virtual ~DeletingLeaf85e510() {}
};
static_assert(sizeof(DeletingLeaf85e510) == 8, "minimal virtual interface size");
