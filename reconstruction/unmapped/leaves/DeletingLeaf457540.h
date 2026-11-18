// Source exposure: binary-analysis
// DeletingLeaf457540, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457540 {
public:
    virtual ~DeletingLeaf457540() {}
};
static_assert(sizeof(DeletingLeaf457540) == 8, "minimal virtual interface size");
