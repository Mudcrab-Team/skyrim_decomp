// Source exposure: binary-analysis
// DeletingLeaf831cc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831cc0 {
public:
    virtual ~DeletingLeaf831cc0() {}
};
static_assert(sizeof(DeletingLeaf831cc0) == 8, "minimal virtual interface size");
