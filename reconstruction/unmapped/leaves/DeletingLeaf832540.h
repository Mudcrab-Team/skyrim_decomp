// Source exposure: binary-analysis
// DeletingLeaf832540, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf832540 {
public:
    virtual ~DeletingLeaf832540() {}
};
static_assert(sizeof(DeletingLeaf832540) == 8, "minimal virtual interface size");
