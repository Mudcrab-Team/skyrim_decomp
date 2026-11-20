// Source exposure: binary-analysis
// DeletingLeaf831ff0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831ff0 {
public:
    virtual ~DeletingLeaf831ff0() {}
};
static_assert(sizeof(DeletingLeaf831ff0) == 8, "minimal virtual interface size");
