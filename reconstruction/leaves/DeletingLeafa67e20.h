// Source exposure: binary-analysis
// DeletingLeafa67e20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafa67e20 {
public:
    virtual ~DeletingLeafa67e20() {}
};
static_assert(sizeof(DeletingLeafa67e20) == 8, "minimal virtual interface size");
