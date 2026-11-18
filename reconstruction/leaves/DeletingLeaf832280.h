// Source exposure: binary-analysis
// DeletingLeaf832280, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf832280 {
public:
    virtual ~DeletingLeaf832280() {}
};
static_assert(sizeof(DeletingLeaf832280) == 8, "minimal virtual interface size");
