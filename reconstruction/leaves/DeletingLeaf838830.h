// Source exposure: binary-analysis
// DeletingLeaf838830, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf838830 {
public:
    virtual ~DeletingLeaf838830() {}
};
static_assert(sizeof(DeletingLeaf838830) == 8, "minimal virtual interface size");
