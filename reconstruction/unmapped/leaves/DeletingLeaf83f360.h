// Source exposure: binary-analysis
// DeletingLeaf83f360, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83f360 {
public:
    virtual ~DeletingLeaf83f360() {}
};
static_assert(sizeof(DeletingLeaf83f360) == 8, "minimal virtual interface size");
