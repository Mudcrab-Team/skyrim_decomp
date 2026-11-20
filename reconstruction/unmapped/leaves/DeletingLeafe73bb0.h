// Source exposure: binary-analysis
// DeletingLeafe73bb0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafe73bb0 {
public:
    virtual ~DeletingLeafe73bb0() {}
};
static_assert(sizeof(DeletingLeafe73bb0) == 8, "minimal virtual interface size");
