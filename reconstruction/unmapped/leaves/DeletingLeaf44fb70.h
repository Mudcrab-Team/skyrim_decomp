// Source exposure: binary-analysis
// DeletingLeaf44fb70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf44fb70 {
public:
    virtual ~DeletingLeaf44fb70() {}
};
static_assert(sizeof(DeletingLeaf44fb70) == 8, "minimal virtual interface size");
