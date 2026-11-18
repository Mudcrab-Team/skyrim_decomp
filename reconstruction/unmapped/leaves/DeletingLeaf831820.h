// Source exposure: binary-analysis
// DeletingLeaf831820, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831820 {
public:
    virtual ~DeletingLeaf831820() {}
};
static_assert(sizeof(DeletingLeaf831820) == 8, "minimal virtual interface size");
