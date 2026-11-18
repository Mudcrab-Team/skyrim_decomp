// Source exposure: binary-analysis
// DeletingLeaf66dc30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66dc30 {
public:
    virtual ~DeletingLeaf66dc30() {}
};
static_assert(sizeof(DeletingLeaf66dc30) == 8, "minimal virtual interface size");
