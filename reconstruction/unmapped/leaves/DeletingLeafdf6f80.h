// Source exposure: binary-analysis
// DeletingLeafdf6f80, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafdf6f80 {
public:
    virtual ~DeletingLeafdf6f80() {}
};
static_assert(sizeof(DeletingLeafdf6f80) == 8, "minimal virtual interface size");
