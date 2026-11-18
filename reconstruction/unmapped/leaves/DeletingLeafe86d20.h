// Source exposure: binary-analysis
// DeletingLeafe86d20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafe86d20 {
public:
    virtual ~DeletingLeafe86d20() {}
};
static_assert(sizeof(DeletingLeafe86d20) == 8, "minimal virtual interface size");
