// Source exposure: binary-analysis
// DeletingLeaffc7490, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaffc7490 {
public:
    virtual ~DeletingLeaffc7490() {}
};
static_assert(sizeof(DeletingLeaffc7490) == 8, "minimal virtual interface size");
