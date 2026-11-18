// Source exposure: binary-analysis
// DeletingLeaf83d210, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83d210 {
public:
    virtual ~DeletingLeaf83d210() {}
};
static_assert(sizeof(DeletingLeaf83d210) == 8, "minimal virtual interface size");
