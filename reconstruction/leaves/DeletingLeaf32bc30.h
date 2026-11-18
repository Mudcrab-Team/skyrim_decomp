// Source exposure: binary-analysis
// DeletingLeaf32bc30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf32bc30 {
public:
    virtual ~DeletingLeaf32bc30() {}
};
static_assert(sizeof(DeletingLeaf32bc30) == 8, "minimal virtual interface size");
