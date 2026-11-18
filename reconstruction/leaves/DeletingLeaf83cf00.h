// Source exposure: binary-analysis
// DeletingLeaf83cf00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83cf00 {
public:
    virtual ~DeletingLeaf83cf00() {}
};
static_assert(sizeof(DeletingLeaf83cf00) == 8, "minimal virtual interface size");
