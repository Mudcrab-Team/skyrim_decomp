// Source exposure: binary-analysis
// DeletingLeafbaaf90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafbaaf90 {
public:
    virtual ~DeletingLeafbaaf90() {}
};
static_assert(sizeof(DeletingLeafbaaf90) == 8, "minimal virtual interface size");
