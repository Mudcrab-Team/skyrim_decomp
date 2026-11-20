// Source exposure: binary-analysis
// DeletingLeaf458b10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458b10 {
public:
    virtual ~DeletingLeaf458b10() {}
};
static_assert(sizeof(DeletingLeaf458b10) == 8, "minimal virtual interface size");
