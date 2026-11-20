// Source exposure: binary-analysis
// DeletingLeaf45eb80, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf45eb80 {
public:
    virtual ~DeletingLeaf45eb80() {}
};
static_assert(sizeof(DeletingLeaf45eb80) == 8, "minimal virtual interface size");
