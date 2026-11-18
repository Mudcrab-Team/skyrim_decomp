// Source exposure: binary-analysis
// DeletingLeaf831870, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831870 {
public:
    virtual ~DeletingLeaf831870() {}
};
static_assert(sizeof(DeletingLeaf831870) == 8, "minimal virtual interface size");
