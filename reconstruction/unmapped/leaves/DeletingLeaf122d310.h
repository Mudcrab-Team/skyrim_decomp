// Source exposure: binary-analysis
// DeletingLeaf122d310, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122d310 {
public:
    virtual ~DeletingLeaf122d310() {}
};
static_assert(sizeof(DeletingLeaf122d310) == 8, "minimal virtual interface size");
