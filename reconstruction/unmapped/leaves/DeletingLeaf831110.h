// Source exposure: binary-analysis
// DeletingLeaf831110, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831110 {
public:
    virtual ~DeletingLeaf831110() {}
};
static_assert(sizeof(DeletingLeaf831110) == 8, "minimal virtual interface size");
