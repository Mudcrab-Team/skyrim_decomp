// Source exposure: binary-analysis
// DeletingLeaf490fb0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf490fb0 {
public:
    virtual ~DeletingLeaf490fb0() {}
};
static_assert(sizeof(DeletingLeaf490fb0) == 8, "minimal virtual interface size");
