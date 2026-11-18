// Source exposure: binary-analysis
// DeletingLeaf831e50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831e50 {
public:
    virtual ~DeletingLeaf831e50() {}
};
static_assert(sizeof(DeletingLeaf831e50) == 8, "minimal virtual interface size");
