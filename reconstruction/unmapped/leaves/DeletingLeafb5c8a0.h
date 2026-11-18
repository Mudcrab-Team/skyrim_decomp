// Source exposure: binary-analysis
// DeletingLeafb5c8a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafb5c8a0 {
public:
    virtual ~DeletingLeafb5c8a0() {}
};
static_assert(sizeof(DeletingLeafb5c8a0) == 8, "minimal virtual interface size");
