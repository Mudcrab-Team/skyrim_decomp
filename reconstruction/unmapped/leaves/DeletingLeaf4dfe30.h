// Source exposure: binary-analysis
// DeletingLeaf4dfe30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4dfe30 {
public:
    virtual ~DeletingLeaf4dfe30() {}
};
static_assert(sizeof(DeletingLeaf4dfe30) == 8, "minimal virtual interface size");
