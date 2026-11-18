// Source exposure: binary-analysis
// DeletingLeaf8beb70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8beb70 {
public:
    virtual ~DeletingLeaf8beb70() {}
};
static_assert(sizeof(DeletingLeaf8beb70) == 8, "minimal virtual interface size");
