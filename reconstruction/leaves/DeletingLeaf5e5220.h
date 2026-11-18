// Source exposure: binary-analysis
// DeletingLeaf5e5220, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf5e5220 {
public:
    virtual ~DeletingLeaf5e5220() {}
};
static_assert(sizeof(DeletingLeaf5e5220) == 8, "minimal virtual interface size");
