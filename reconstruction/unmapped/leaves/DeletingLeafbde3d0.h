// Source exposure: binary-analysis
// DeletingLeafbde3d0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafbde3d0 {
public:
    virtual ~DeletingLeafbde3d0() {}
};
static_assert(sizeof(DeletingLeafbde3d0) == 8, "minimal virtual interface size");
