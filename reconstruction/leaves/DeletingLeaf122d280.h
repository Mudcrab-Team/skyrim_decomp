// Source exposure: binary-analysis
// DeletingLeaf122d280, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122d280 {
public:
    virtual ~DeletingLeaf122d280() {}
};
static_assert(sizeof(DeletingLeaf122d280) == 8, "minimal virtual interface size");
