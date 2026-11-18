// Source exposure: binary-analysis
// DeletingLeaf156a740, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf156a740 {
public:
    virtual ~DeletingLeaf156a740() {}
};
static_assert(sizeof(DeletingLeaf156a740) == 8, "minimal virtual interface size");
