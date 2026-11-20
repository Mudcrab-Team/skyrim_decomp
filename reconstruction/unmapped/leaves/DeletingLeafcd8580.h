// Source exposure: binary-analysis
// DeletingLeafcd8580, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafcd8580 {
public:
    virtual ~DeletingLeafcd8580() {}
};
static_assert(sizeof(DeletingLeafcd8580) == 8, "minimal virtual interface size");
