// Source exposure: binary-analysis
// DeletingLeaff38340, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaff38340 {
public:
    virtual ~DeletingLeaff38340() {}
};
static_assert(sizeof(DeletingLeaff38340) == 8, "minimal virtual interface size");
