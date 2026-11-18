// Source exposure: binary-analysis
// DeletingLeafa67e50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafa67e50 {
public:
    virtual ~DeletingLeafa67e50() {}
};
static_assert(sizeof(DeletingLeafa67e50) == 8, "minimal virtual interface size");
