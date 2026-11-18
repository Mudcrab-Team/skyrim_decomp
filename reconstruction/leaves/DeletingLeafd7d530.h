// Source exposure: binary-analysis
// DeletingLeafd7d530, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd7d530 {
public:
    virtual ~DeletingLeafd7d530() {}
};
static_assert(sizeof(DeletingLeafd7d530) == 8, "minimal virtual interface size");
