// Source exposure: binary-analysis
// DeletingLeaf10c490, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf10c490 {
public:
    virtual ~DeletingLeaf10c490() {}
};
static_assert(sizeof(DeletingLeaf10c490) == 8, "minimal virtual interface size");
