// Source exposure: binary-analysis
// DeletingLeaf1599830, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1599830 {
public:
    virtual ~DeletingLeaf1599830() {}
};
static_assert(sizeof(DeletingLeaf1599830) == 8, "minimal virtual interface size");
