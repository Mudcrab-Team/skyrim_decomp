// Source exposure: binary-analysis
// DeletingLeafce4720, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafce4720 {
public:
    virtual ~DeletingLeafce4720() {}
};
static_assert(sizeof(DeletingLeafce4720) == 8, "minimal virtual interface size");
