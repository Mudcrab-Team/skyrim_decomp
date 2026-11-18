// Source exposure: binary-analysis
// DeletingLeafd7a0a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd7a0a0 {
public:
    virtual ~DeletingLeafd7a0a0() {}
};
static_assert(sizeof(DeletingLeafd7a0a0) == 8, "minimal virtual interface size");
