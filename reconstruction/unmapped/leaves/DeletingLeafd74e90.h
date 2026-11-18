// Source exposure: binary-analysis
// DeletingLeafd74e90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd74e90 {
public:
    virtual ~DeletingLeafd74e90() {}
};
static_assert(sizeof(DeletingLeafd74e90) == 8, "minimal virtual interface size");
