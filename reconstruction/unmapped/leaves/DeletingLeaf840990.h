// Source exposure: binary-analysis
// DeletingLeaf840990, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf840990 {
public:
    virtual ~DeletingLeaf840990() {}
};
static_assert(sizeof(DeletingLeaf840990) == 8, "minimal virtual interface size");
