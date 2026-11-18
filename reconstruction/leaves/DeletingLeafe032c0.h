// Source exposure: binary-analysis
// DeletingLeafe032c0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafe032c0 {
public:
    virtual ~DeletingLeafe032c0() {}
};
static_assert(sizeof(DeletingLeafe032c0) == 8, "minimal virtual interface size");
