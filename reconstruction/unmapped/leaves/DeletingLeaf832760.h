// Source exposure: binary-analysis
// DeletingLeaf832760, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf832760 {
public:
    virtual ~DeletingLeaf832760() {}
};
static_assert(sizeof(DeletingLeaf832760) == 8, "minimal virtual interface size");
