// Source exposure: binary-analysis
// DeletingLeaf83c260, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83c260 {
public:
    virtual ~DeletingLeaf83c260() {}
};
static_assert(sizeof(DeletingLeaf83c260) == 8, "minimal virtual interface size");
