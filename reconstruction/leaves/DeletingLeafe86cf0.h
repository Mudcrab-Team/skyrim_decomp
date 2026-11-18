// Source exposure: binary-analysis
// DeletingLeafe86cf0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafe86cf0 {
public:
    virtual ~DeletingLeafe86cf0() {}
};
static_assert(sizeof(DeletingLeafe86cf0) == 8, "minimal virtual interface size");
