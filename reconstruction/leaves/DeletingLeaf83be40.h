// Source exposure: binary-analysis
// DeletingLeaf83be40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83be40 {
public:
    virtual ~DeletingLeaf83be40() {}
};
static_assert(sizeof(DeletingLeaf83be40) == 8, "minimal virtual interface size");
