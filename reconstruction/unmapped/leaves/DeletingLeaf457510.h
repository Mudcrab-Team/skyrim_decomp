// Source exposure: binary-analysis
// DeletingLeaf457510, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457510 {
public:
    virtual ~DeletingLeaf457510() {}
};
static_assert(sizeof(DeletingLeaf457510) == 8, "minimal virtual interface size");
