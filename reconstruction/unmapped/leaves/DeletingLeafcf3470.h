// Source exposure: binary-analysis
// DeletingLeafcf3470, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafcf3470 {
public:
    virtual ~DeletingLeafcf3470() {}
};
static_assert(sizeof(DeletingLeafcf3470) == 8, "minimal virtual interface size");
