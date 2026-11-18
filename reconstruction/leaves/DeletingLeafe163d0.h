// Source exposure: binary-analysis
// DeletingLeafe163d0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafe163d0 {
public:
    virtual ~DeletingLeafe163d0() {}
};
static_assert(sizeof(DeletingLeafe163d0) == 8, "minimal virtual interface size");
