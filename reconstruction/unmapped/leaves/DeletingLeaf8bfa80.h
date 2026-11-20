// Source exposure: binary-analysis
// DeletingLeaf8bfa80, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8bfa80 {
public:
    virtual ~DeletingLeaf8bfa80() {}
};
static_assert(sizeof(DeletingLeaf8bfa80) == 8, "minimal virtual interface size");
