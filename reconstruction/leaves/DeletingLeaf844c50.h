// Source exposure: binary-analysis
// DeletingLeaf844c50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf844c50 {
public:
    virtual ~DeletingLeaf844c50() {}
};
static_assert(sizeof(DeletingLeaf844c50) == 8, "minimal virtual interface size");
