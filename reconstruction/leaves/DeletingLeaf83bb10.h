// Source exposure: binary-analysis
// DeletingLeaf83bb10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83bb10 {
public:
    virtual ~DeletingLeaf83bb10() {}
};
static_assert(sizeof(DeletingLeaf83bb10) == 8, "minimal virtual interface size");
