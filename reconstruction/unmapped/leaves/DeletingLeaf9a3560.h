// Source exposure: binary-analysis
// DeletingLeaf9a3560, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9a3560 {
public:
    virtual ~DeletingLeaf9a3560() {}
};
static_assert(sizeof(DeletingLeaf9a3560) == 8, "minimal virtual interface size");
