// Source exposure: binary-analysis
// DeletingLeaf32bc90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf32bc90 {
public:
    virtual ~DeletingLeaf32bc90() {}
};
static_assert(sizeof(DeletingLeaf32bc90) == 8, "minimal virtual interface size");
