// Source exposure: binary-analysis
// DeletingLeafd41580, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd41580 {
public:
    virtual ~DeletingLeafd41580() {}
};
static_assert(sizeof(DeletingLeafd41580) == 8, "minimal virtual interface size");
