// Source exposure: binary-analysis
// DeletingLeafe86c90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafe86c90 {
public:
    virtual ~DeletingLeafe86c90() {}
};
static_assert(sizeof(DeletingLeafe86c90) == 8, "minimal virtual interface size");
