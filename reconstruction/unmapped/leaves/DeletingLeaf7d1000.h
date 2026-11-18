// Source exposure: binary-analysis
// DeletingLeaf7d1000, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7d1000 {
public:
    virtual ~DeletingLeaf7d1000() {}
};
static_assert(sizeof(DeletingLeaf7d1000) == 8, "minimal virtual interface size");
