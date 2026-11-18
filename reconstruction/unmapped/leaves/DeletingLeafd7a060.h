// Source exposure: binary-analysis
// DeletingLeafd7a060, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd7a060 {
public:
    virtual ~DeletingLeafd7a060() {}
};
static_assert(sizeof(DeletingLeafd7a060) == 8, "minimal virtual interface size");
