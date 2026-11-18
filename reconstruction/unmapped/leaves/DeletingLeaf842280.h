// Source exposure: binary-analysis
// DeletingLeaf842280, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf842280 {
public:
    virtual ~DeletingLeaf842280() {}
};
static_assert(sizeof(DeletingLeaf842280) == 8, "minimal virtual interface size");
