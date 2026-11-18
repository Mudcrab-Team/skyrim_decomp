// Source exposure: binary-analysis
// DeletingLeaf449660, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf449660 {
public:
    virtual ~DeletingLeaf449660() {}
};
static_assert(sizeof(DeletingLeaf449660) == 8, "minimal virtual interface size");
