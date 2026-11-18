// Source exposure: binary-analysis
// DeletingLeaf450170, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf450170 {
public:
    virtual ~DeletingLeaf450170() {}
};
static_assert(sizeof(DeletingLeaf450170) == 8, "minimal virtual interface size");
