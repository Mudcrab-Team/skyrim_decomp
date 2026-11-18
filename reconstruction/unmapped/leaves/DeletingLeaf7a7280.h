// Source exposure: binary-analysis
// DeletingLeaf7a7280, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7a7280 {
public:
    virtual ~DeletingLeaf7a7280() {}
};
static_assert(sizeof(DeletingLeaf7a7280) == 8, "minimal virtual interface size");
