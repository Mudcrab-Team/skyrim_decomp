// Source exposure: binary-analysis
// DeletingLeaf7d2800, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7d2800 {
public:
    virtual ~DeletingLeaf7d2800() {}
};
static_assert(sizeof(DeletingLeaf7d2800) == 8, "minimal virtual interface size");
