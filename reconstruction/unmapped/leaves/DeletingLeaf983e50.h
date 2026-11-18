// Source exposure: binary-analysis
// DeletingLeaf983e50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf983e50 {
public:
    virtual ~DeletingLeaf983e50() {}
};
static_assert(sizeof(DeletingLeaf983e50) == 8, "minimal virtual interface size");
