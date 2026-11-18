// Source exposure: binary-analysis
// DeletingLeafa67df0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafa67df0 {
public:
    virtual ~DeletingLeafa67df0() {}
};
static_assert(sizeof(DeletingLeafa67df0) == 8, "minimal virtual interface size");
