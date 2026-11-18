// Source exposure: binary-analysis
// DeletingLeaf449630, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf449630 {
public:
    virtual ~DeletingLeaf449630() {}
};
static_assert(sizeof(DeletingLeaf449630) == 8, "minimal virtual interface size");
