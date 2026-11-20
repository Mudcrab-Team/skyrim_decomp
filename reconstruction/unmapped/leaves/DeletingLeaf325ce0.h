// Source exposure: binary-analysis
// DeletingLeaf325ce0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf325ce0 {
public:
    virtual ~DeletingLeaf325ce0() {}
};
static_assert(sizeof(DeletingLeaf325ce0) == 8, "minimal virtual interface size");
