// Source exposure: binary-analysis
// DeletingLeaf831300, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831300 {
public:
    virtual ~DeletingLeaf831300() {}
};
static_assert(sizeof(DeletingLeaf831300) == 8, "minimal virtual interface size");
