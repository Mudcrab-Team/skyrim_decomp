// Source exposure: binary-analysis
// DeletingLeaf893d70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf893d70 {
public:
    virtual ~DeletingLeaf893d70() {}
};
static_assert(sizeof(DeletingLeaf893d70) == 8, "minimal virtual interface size");
