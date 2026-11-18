// Source exposure: binary-analysis
// DeletingLeaf831a30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831a30 {
public:
    virtual ~DeletingLeaf831a30() {}
};
static_assert(sizeof(DeletingLeaf831a30) == 8, "minimal virtual interface size");
