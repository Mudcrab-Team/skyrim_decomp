// Source exposure: binary-analysis
// DeletingLeafd1d410, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd1d410 {
public:
    virtual ~DeletingLeafd1d410() {}
};
static_assert(sizeof(DeletingLeafd1d410) == 8, "minimal virtual interface size");
