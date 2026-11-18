// Source exposure: binary-analysis
// DeletingLeafeaea50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafeaea50 {
public:
    virtual ~DeletingLeafeaea50() {}
};
static_assert(sizeof(DeletingLeafeaea50) == 8, "minimal virtual interface size");
