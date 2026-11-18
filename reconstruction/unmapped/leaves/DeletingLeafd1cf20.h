// Source exposure: binary-analysis
// DeletingLeafd1cf20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd1cf20 {
public:
    virtual ~DeletingLeafd1cf20() {}
};
static_assert(sizeof(DeletingLeafd1cf20) == 8, "minimal virtual interface size");
