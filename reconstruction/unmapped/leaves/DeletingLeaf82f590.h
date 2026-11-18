// Source exposure: binary-analysis
// DeletingLeaf82f590, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf82f590 {
public:
    virtual ~DeletingLeaf82f590() {}
};
static_assert(sizeof(DeletingLeaf82f590) == 8, "minimal virtual interface size");
