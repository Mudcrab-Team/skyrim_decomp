// Source exposure: binary-analysis
// DeletingLeafd406b0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd406b0 {
public:
    virtual ~DeletingLeafd406b0() {}
};
static_assert(sizeof(DeletingLeafd406b0) == 8, "minimal virtual interface size");
