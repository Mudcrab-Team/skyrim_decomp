// Source exposure: binary-analysis
// DeletingLeaf831440, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831440 {
public:
    virtual ~DeletingLeaf831440() {}
};
static_assert(sizeof(DeletingLeaf831440) == 8, "minimal virtual interface size");
