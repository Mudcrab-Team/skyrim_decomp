// Source exposure: binary-analysis
// DeletingLeaf325eb0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf325eb0 {
public:
    virtual ~DeletingLeaf325eb0() {}
};
static_assert(sizeof(DeletingLeaf325eb0) == 8, "minimal virtual interface size");
