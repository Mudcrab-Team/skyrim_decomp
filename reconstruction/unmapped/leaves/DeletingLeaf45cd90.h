// Source exposure: binary-analysis
// DeletingLeaf45cd90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf45cd90 {
public:
    virtual ~DeletingLeaf45cd90() {}
};
static_assert(sizeof(DeletingLeaf45cd90) == 8, "minimal virtual interface size");
