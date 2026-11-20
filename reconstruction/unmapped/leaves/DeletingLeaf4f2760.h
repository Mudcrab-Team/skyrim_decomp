// Source exposure: binary-analysis
// DeletingLeaf4f2760, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4f2760 {
public:
    virtual ~DeletingLeaf4f2760() {}
};
static_assert(sizeof(DeletingLeaf4f2760) == 8, "minimal virtual interface size");
