// Source exposure: binary-analysis
// DeletingLeaf452780, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf452780 {
public:
    virtual ~DeletingLeaf452780() {}
};
static_assert(sizeof(DeletingLeaf452780) == 8, "minimal virtual interface size");
