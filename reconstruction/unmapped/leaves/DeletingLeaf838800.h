// Source exposure: binary-analysis
// DeletingLeaf838800, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf838800 {
public:
    virtual ~DeletingLeaf838800() {}
};
static_assert(sizeof(DeletingLeaf838800) == 8, "minimal virtual interface size");
