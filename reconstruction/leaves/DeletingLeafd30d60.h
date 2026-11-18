// Source exposure: binary-analysis
// DeletingLeafd30d60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd30d60 {
public:
    virtual ~DeletingLeafd30d60() {}
};
static_assert(sizeof(DeletingLeafd30d60) == 8, "minimal virtual interface size");
