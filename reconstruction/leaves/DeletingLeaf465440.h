// Source exposure: binary-analysis
// DeletingLeaf465440, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf465440 {
public:
    virtual ~DeletingLeaf465440() {}
};
static_assert(sizeof(DeletingLeaf465440) == 8, "minimal virtual interface size");
