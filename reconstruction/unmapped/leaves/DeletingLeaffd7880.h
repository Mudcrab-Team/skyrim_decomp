// Source exposure: binary-analysis
// DeletingLeaffd7880, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaffd7880 {
public:
    virtual ~DeletingLeaffd7880() {}
};
static_assert(sizeof(DeletingLeaffd7880) == 8, "minimal virtual interface size");
