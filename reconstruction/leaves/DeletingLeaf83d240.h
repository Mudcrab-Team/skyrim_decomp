// Source exposure: binary-analysis
// DeletingLeaf83d240, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83d240 {
public:
    virtual ~DeletingLeaf83d240() {}
};
static_assert(sizeof(DeletingLeaf83d240) == 8, "minimal virtual interface size");
