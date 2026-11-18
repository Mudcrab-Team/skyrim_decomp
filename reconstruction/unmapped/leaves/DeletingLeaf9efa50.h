// Source exposure: binary-analysis
// DeletingLeaf9efa50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9efa50 {
public:
    virtual ~DeletingLeaf9efa50() {}
};
static_assert(sizeof(DeletingLeaf9efa50) == 8, "minimal virtual interface size");
