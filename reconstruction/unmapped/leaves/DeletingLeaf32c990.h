// Source exposure: binary-analysis
// DeletingLeaf32c990, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf32c990 {
public:
    virtual ~DeletingLeaf32c990() {}
};
static_assert(sizeof(DeletingLeaf32c990) == 8, "minimal virtual interface size");
