// Source exposure: binary-analysis
// DeletingLeaf45eb50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf45eb50 {
public:
    virtual ~DeletingLeaf45eb50() {}
};
static_assert(sizeof(DeletingLeaf45eb50) == 8, "minimal virtual interface size");
