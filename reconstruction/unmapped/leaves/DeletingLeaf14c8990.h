// Source exposure: binary-analysis
// DeletingLeaf14c8990, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf14c8990 {
public:
    virtual ~DeletingLeaf14c8990() {}
};
static_assert(sizeof(DeletingLeaf14c8990) == 8, "minimal virtual interface size");
