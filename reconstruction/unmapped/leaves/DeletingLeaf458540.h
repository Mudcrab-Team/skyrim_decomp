// Source exposure: binary-analysis
// DeletingLeaf458540, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458540 {
public:
    virtual ~DeletingLeaf458540() {}
};
static_assert(sizeof(DeletingLeaf458540) == 8, "minimal virtual interface size");
