// Source exposure: binary-analysis
// DeletingLeaf449690, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf449690 {
public:
    virtual ~DeletingLeaf449690() {}
};
static_assert(sizeof(DeletingLeaf449690) == 8, "minimal virtual interface size");
