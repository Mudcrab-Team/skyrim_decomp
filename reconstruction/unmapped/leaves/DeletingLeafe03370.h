// Source exposure: binary-analysis
// DeletingLeafe03370, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafe03370 {
public:
    virtual ~DeletingLeafe03370() {}
};
static_assert(sizeof(DeletingLeafe03370) == 8, "minimal virtual interface size");
