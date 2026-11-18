// Source exposure: binary-analysis
// DeletingLeafe348a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafe348a0 {
public:
    virtual ~DeletingLeafe348a0() {}
};
static_assert(sizeof(DeletingLeafe348a0) == 8, "minimal virtual interface size");
