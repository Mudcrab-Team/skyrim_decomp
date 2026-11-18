// Source exposure: binary-analysis
// DeletingLeaf85e540, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf85e540 {
public:
    virtual ~DeletingLeaf85e540() {}
};
static_assert(sizeof(DeletingLeaf85e540) == 8, "minimal virtual interface size");
