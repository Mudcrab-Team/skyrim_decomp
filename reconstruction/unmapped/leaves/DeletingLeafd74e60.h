// Source exposure: binary-analysis
// DeletingLeafd74e60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd74e60 {
public:
    virtual ~DeletingLeafd74e60() {}
};
static_assert(sizeof(DeletingLeafd74e60) == 8, "minimal virtual interface size");
