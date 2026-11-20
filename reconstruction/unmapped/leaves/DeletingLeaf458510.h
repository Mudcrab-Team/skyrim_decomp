// Source exposure: binary-analysis
// DeletingLeaf458510, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458510 {
public:
    virtual ~DeletingLeaf458510() {}
};
static_assert(sizeof(DeletingLeaf458510) == 8, "minimal virtual interface size");
