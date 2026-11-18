// Source exposure: binary-analysis
// DeletingLeaf893e00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf893e00 {
public:
    virtual ~DeletingLeaf893e00() {}
};
static_assert(sizeof(DeletingLeaf893e00) == 8, "minimal virtual interface size");
