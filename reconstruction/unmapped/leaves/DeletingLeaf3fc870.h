// Source exposure: binary-analysis
// DeletingLeaf3fc870, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf3fc870 {
public:
    virtual ~DeletingLeaf3fc870() {}
};
static_assert(sizeof(DeletingLeaf3fc870) == 8, "minimal virtual interface size");
