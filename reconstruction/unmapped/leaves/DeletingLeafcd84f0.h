// Source exposure: binary-analysis
// DeletingLeafcd84f0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafcd84f0 {
public:
    virtual ~DeletingLeafcd84f0() {}
};
static_assert(sizeof(DeletingLeafcd84f0) == 8, "minimal virtual interface size");
