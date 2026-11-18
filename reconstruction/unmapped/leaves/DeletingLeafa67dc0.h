// Source exposure: binary-analysis
// DeletingLeafa67dc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafa67dc0 {
public:
    virtual ~DeletingLeafa67dc0() {}
};
static_assert(sizeof(DeletingLeafa67dc0) == 8, "minimal virtual interface size");
