// Source exposure: binary-analysis
// DeletingLeaf9b2a50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9b2a50 {
public:
    virtual ~DeletingLeaf9b2a50() {}
};
static_assert(sizeof(DeletingLeaf9b2a50) == 8, "minimal virtual interface size");
