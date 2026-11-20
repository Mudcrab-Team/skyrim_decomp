// Source exposure: binary-analysis
// DeletingLeaf831b30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831b30 {
public:
    virtual ~DeletingLeaf831b30() {}
};
static_assert(sizeof(DeletingLeaf831b30) == 8, "minimal virtual interface size");
