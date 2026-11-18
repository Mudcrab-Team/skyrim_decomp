// Source exposure: binary-analysis
// DeletingLeafeae930, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafeae930 {
public:
    virtual ~DeletingLeafeae930() {}
};
static_assert(sizeof(DeletingLeafeae930) == 8, "minimal virtual interface size");
