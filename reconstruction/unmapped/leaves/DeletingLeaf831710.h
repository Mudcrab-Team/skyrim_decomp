// Source exposure: binary-analysis
// DeletingLeaf831710, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831710 {
public:
    virtual ~DeletingLeaf831710() {}
};
static_assert(sizeof(DeletingLeaf831710) == 8, "minimal virtual interface size");
