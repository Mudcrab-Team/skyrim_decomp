// Source exposure: binary-analysis
// DeletingLeaf7ab380, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7ab380 {
public:
    virtual ~DeletingLeaf7ab380() {}
};
static_assert(sizeof(DeletingLeaf7ab380) == 8, "minimal virtual interface size");
