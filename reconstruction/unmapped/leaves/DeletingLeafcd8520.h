// Source exposure: binary-analysis
// DeletingLeafcd8520, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafcd8520 {
public:
    virtual ~DeletingLeafcd8520() {}
};
static_assert(sizeof(DeletingLeafcd8520) == 8, "minimal virtual interface size");
