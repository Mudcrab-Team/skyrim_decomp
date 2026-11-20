// Source exposure: binary-analysis
// DeletingLeaf82f430, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf82f430 {
public:
    virtual ~DeletingLeaf82f430() {}
};
static_assert(sizeof(DeletingLeaf82f430) == 8, "minimal virtual interface size");
