// Source exposure: binary-analysis
// DeletingLeaf449780, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf449780 {
public:
    virtual ~DeletingLeaf449780() {}
};
static_assert(sizeof(DeletingLeaf449780) == 8, "minimal virtual interface size");
