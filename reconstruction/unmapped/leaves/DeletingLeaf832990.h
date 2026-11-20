// Source exposure: binary-analysis
// DeletingLeaf832990, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf832990 {
public:
    virtual ~DeletingLeaf832990() {}
};
static_assert(sizeof(DeletingLeaf832990) == 8, "minimal virtual interface size");
