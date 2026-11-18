// Source exposure: binary-analysis
// DeletingLeafc414f0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafc414f0 {
public:
    virtual ~DeletingLeafc414f0() {}
};
static_assert(sizeof(DeletingLeafc414f0) == 8, "minimal virtual interface size");
