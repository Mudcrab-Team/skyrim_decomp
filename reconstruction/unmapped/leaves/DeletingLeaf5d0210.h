// Source exposure: binary-analysis
// DeletingLeaf5d0210, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf5d0210 {
public:
    virtual ~DeletingLeaf5d0210() {}
};
static_assert(sizeof(DeletingLeaf5d0210) == 8, "minimal virtual interface size");
