// Source exposure: binary-analysis
// DeletingLeafa7e450, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafa7e450 {
public:
    virtual ~DeletingLeafa7e450() {}
};
static_assert(sizeof(DeletingLeafa7e450) == 8, "minimal virtual interface size");
