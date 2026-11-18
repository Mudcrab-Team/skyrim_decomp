// Source exposure: binary-analysis
// DeletingLeaf83fd00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83fd00 {
public:
    virtual ~DeletingLeaf83fd00() {}
};
static_assert(sizeof(DeletingLeaf83fd00) == 8, "minimal virtual interface size");
