// Source exposure: binary-analysis
// DeletingLeaf9efe40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9efe40 {
public:
    virtual ~DeletingLeaf9efe40() {}
};
static_assert(sizeof(DeletingLeaf9efe40) == 8, "minimal virtual interface size");
