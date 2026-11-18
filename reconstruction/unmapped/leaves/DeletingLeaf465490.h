// Source exposure: binary-analysis
// DeletingLeaf465490, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf465490 {
public:
    virtual ~DeletingLeaf465490() {}
};
static_assert(sizeof(DeletingLeaf465490) == 8, "minimal virtual interface size");
