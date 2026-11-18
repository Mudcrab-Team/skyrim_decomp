// Source exposure: binary-analysis
// DeletingLeaf89b830, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf89b830 {
public:
    virtual ~DeletingLeaf89b830() {}
};
static_assert(sizeof(DeletingLeaf89b830) == 8, "minimal virtual interface size");
