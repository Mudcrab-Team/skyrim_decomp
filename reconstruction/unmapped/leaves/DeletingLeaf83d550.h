// Source exposure: binary-analysis
// DeletingLeaf83d550, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83d550 {
public:
    virtual ~DeletingLeaf83d550() {}
};
static_assert(sizeof(DeletingLeaf83d550) == 8, "minimal virtual interface size");
