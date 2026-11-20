// Source exposure: binary-analysis
// DeletingLeafd7d8d0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd7d8d0 {
public:
    virtual ~DeletingLeafd7d8d0() {}
};
static_assert(sizeof(DeletingLeafd7d8d0) == 8, "minimal virtual interface size");
