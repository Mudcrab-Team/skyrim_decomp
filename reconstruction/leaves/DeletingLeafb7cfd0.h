// Source exposure: binary-analysis
// DeletingLeafb7cfd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafb7cfd0 {
public:
    virtual ~DeletingLeafb7cfd0() {}
};
static_assert(sizeof(DeletingLeafb7cfd0) == 8, "minimal virtual interface size");
