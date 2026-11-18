// Source exposure: binary-analysis
// DeletingLeaf44fe00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf44fe00 {
public:
    virtual ~DeletingLeaf44fe00() {}
};
static_assert(sizeof(DeletingLeaf44fe00) == 8, "minimal virtual interface size");
