// Source exposure: binary-analysis
// DeletingLeaf83c230, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83c230 {
public:
    virtual ~DeletingLeaf83c230() {}
};
static_assert(sizeof(DeletingLeaf83c230) == 8, "minimal virtual interface size");
