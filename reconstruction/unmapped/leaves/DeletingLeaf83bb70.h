// Source exposure: binary-analysis
// DeletingLeaf83bb70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83bb70 {
public:
    virtual ~DeletingLeaf83bb70() {}
};
static_assert(sizeof(DeletingLeaf83bb70) == 8, "minimal virtual interface size");
