// Source exposure: binary-analysis
// DeletingLeaf8cc230, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8cc230 {
public:
    virtual ~DeletingLeaf8cc230() {}
};
static_assert(sizeof(DeletingLeaf8cc230) == 8, "minimal virtual interface size");
