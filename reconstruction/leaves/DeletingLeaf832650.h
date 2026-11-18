// Source exposure: binary-analysis
// DeletingLeaf832650, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf832650 {
public:
    virtual ~DeletingLeaf832650() {}
};
static_assert(sizeof(DeletingLeaf832650) == 8, "minimal virtual interface size");
