// Source exposure: binary-analysis
// DeletingLeaf457a50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457a50 {
public:
    virtual ~DeletingLeaf457a50() {}
};
static_assert(sizeof(DeletingLeaf457a50) == 8, "minimal virtual interface size");
