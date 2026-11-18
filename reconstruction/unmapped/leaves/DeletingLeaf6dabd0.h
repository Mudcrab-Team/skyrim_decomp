// Source exposure: binary-analysis
// DeletingLeaf6dabd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf6dabd0 {
public:
    virtual ~DeletingLeaf6dabd0() {}
};
static_assert(sizeof(DeletingLeaf6dabd0) == 8, "minimal virtual interface size");
