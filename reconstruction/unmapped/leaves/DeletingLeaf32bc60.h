// Source exposure: binary-analysis
// DeletingLeaf32bc60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf32bc60 {
public:
    virtual ~DeletingLeaf32bc60() {}
};
static_assert(sizeof(DeletingLeaf32bc60) == 8, "minimal virtual interface size");
