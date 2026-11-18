// Source exposure: binary-analysis
// DeletingLeaf893a80, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf893a80 {
public:
    virtual ~DeletingLeaf893a80() {}
};
static_assert(sizeof(DeletingLeaf893a80) == 8, "minimal virtual interface size");
