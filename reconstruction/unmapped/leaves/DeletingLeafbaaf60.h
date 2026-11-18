// Source exposure: binary-analysis
// DeletingLeafbaaf60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafbaaf60 {
public:
    virtual ~DeletingLeafbaaf60() {}
};
static_assert(sizeof(DeletingLeafbaaf60) == 8, "minimal virtual interface size");
