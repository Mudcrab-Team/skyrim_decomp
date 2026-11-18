// Source exposure: binary-analysis
// DeletingLeaf83b680, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83b680 {
public:
    virtual ~DeletingLeaf83b680() {}
};
static_assert(sizeof(DeletingLeaf83b680) == 8, "minimal virtual interface size");
