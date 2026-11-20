// Source exposure: binary-analysis
// DeletingLeaf844c20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf844c20 {
public:
    virtual ~DeletingLeaf844c20() {}
};
static_assert(sizeof(DeletingLeaf844c20) == 8, "minimal virtual interface size");
