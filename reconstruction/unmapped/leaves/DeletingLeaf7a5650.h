// Source exposure: binary-analysis
// DeletingLeaf7a5650, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7a5650 {
public:
    virtual ~DeletingLeaf7a5650() {}
};
static_assert(sizeof(DeletingLeaf7a5650) == 8, "minimal virtual interface size");
