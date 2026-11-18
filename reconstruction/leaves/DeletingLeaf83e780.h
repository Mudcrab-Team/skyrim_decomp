// Source exposure: binary-analysis
// DeletingLeaf83e780, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83e780 {
public:
    virtual ~DeletingLeaf83e780() {}
};
static_assert(sizeof(DeletingLeaf83e780) == 8, "minimal virtual interface size");
