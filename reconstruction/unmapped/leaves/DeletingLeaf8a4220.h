// Source exposure: binary-analysis
// DeletingLeaf8a4220, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8a4220 {
public:
    virtual ~DeletingLeaf8a4220() {}
};
static_assert(sizeof(DeletingLeaf8a4220) == 8, "minimal virtual interface size");
