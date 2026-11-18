// Source exposure: binary-analysis
// DeletingLeaf122be50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122be50 {
public:
    virtual ~DeletingLeaf122be50() {}
};
static_assert(sizeof(DeletingLeaf122be50) == 8, "minimal virtual interface size");
