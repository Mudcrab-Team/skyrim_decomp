// Source exposure: binary-analysis
// DeletingLeafcd62e0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafcd62e0 {
public:
    virtual ~DeletingLeafcd62e0() {}
};
static_assert(sizeof(DeletingLeafcd62e0) == 8, "minimal virtual interface size");
