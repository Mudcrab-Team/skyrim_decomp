// Source exposure: binary-analysis
// DeletingLeaf810f60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf810f60 {
public:
    virtual ~DeletingLeaf810f60() {}
};
static_assert(sizeof(DeletingLeaf810f60) == 8, "minimal virtual interface size");
