// Source exposure: binary-analysis
// DeletingLeaf503a00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf503a00 {
public:
    virtual ~DeletingLeaf503a00() {}
};
static_assert(sizeof(DeletingLeaf503a00) == 8, "minimal virtual interface size");
