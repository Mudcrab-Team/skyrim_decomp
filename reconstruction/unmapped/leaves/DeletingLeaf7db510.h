// Source exposure: binary-analysis
// DeletingLeaf7db510, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7db510 {
public:
    virtual ~DeletingLeaf7db510() {}
};
static_assert(sizeof(DeletingLeaf7db510) == 8, "minimal virtual interface size");
