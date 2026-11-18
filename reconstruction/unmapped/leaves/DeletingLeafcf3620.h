// Source exposure: binary-analysis
// DeletingLeafcf3620, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafcf3620 {
public:
    virtual ~DeletingLeafcf3620() {}
};
static_assert(sizeof(DeletingLeafcf3620) == 8, "minimal virtual interface size");
