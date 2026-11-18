// Source exposure: binary-analysis
// DeletingLeaf457450, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457450 {
public:
    virtual ~DeletingLeaf457450() {}
};
static_assert(sizeof(DeletingLeaf457450) == 8, "minimal virtual interface size");
