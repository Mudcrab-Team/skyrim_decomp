// Source exposure: binary-analysis
// DeletingLeaf46e9d0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf46e9d0 {
public:
    virtual ~DeletingLeaf46e9d0() {}
};
static_assert(sizeof(DeletingLeaf46e9d0) == 8, "minimal virtual interface size");
