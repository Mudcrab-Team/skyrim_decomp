// Source exposure: binary-analysis
// DeletingLeaf82fef0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf82fef0 {
public:
    virtual ~DeletingLeaf82fef0() {}
};
static_assert(sizeof(DeletingLeaf82fef0) == 8, "minimal virtual interface size");
