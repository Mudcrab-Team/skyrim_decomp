// Source exposure: binary-analysis
// DeletingLeafce4760, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafce4760 {
public:
    virtual ~DeletingLeafce4760() {}
};
static_assert(sizeof(DeletingLeafce4760) == 8, "minimal virtual interface size");
