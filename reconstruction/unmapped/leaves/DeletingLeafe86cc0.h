// Source exposure: binary-analysis
// DeletingLeafe86cc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafe86cc0 {
public:
    virtual ~DeletingLeafe86cc0() {}
};
static_assert(sizeof(DeletingLeafe86cc0) == 8, "minimal virtual interface size");
