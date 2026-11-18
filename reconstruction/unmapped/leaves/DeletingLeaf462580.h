// Source exposure: binary-analysis
// DeletingLeaf462580, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf462580 {
public:
    virtual ~DeletingLeaf462580() {}
};
static_assert(sizeof(DeletingLeaf462580) == 8, "minimal virtual interface size");
