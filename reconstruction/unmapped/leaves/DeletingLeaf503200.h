// Source exposure: binary-analysis
// DeletingLeaf503200, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf503200 {
public:
    virtual ~DeletingLeaf503200() {}
};
static_assert(sizeof(DeletingLeaf503200) == 8, "minimal virtual interface size");
