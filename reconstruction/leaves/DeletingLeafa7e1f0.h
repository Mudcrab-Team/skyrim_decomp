// Source exposure: binary-analysis
// DeletingLeafa7e1f0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafa7e1f0 {
public:
    virtual ~DeletingLeafa7e1f0() {}
};
static_assert(sizeof(DeletingLeafa7e1f0) == 8, "minimal virtual interface size");
