// Source exposure: binary-analysis
// DeletingLeaf7a8f00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7a8f00 {
public:
    virtual ~DeletingLeaf7a8f00() {}
};
static_assert(sizeof(DeletingLeaf7a8f00) == 8, "minimal virtual interface size");
