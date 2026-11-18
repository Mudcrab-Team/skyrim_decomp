// Source exposure: binary-analysis
// DeletingLeaf845b50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf845b50 {
public:
    virtual ~DeletingLeaf845b50() {}
};
static_assert(sizeof(DeletingLeaf845b50) == 8, "minimal virtual interface size");
