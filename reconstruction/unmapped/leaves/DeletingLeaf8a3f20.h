// Source exposure: binary-analysis
// DeletingLeaf8a3f20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8a3f20 {
public:
    virtual ~DeletingLeaf8a3f20() {}
};
static_assert(sizeof(DeletingLeaf8a3f20) == 8, "minimal virtual interface size");
