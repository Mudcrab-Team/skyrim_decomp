// Source exposure: binary-analysis
// DeletingLeafe6dec0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafe6dec0 {
public:
    virtual ~DeletingLeafe6dec0() {}
};
static_assert(sizeof(DeletingLeafe6dec0) == 8, "minimal virtual interface size");
