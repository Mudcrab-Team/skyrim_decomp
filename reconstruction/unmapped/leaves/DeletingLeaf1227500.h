// Source exposure: binary-analysis
// DeletingLeaf1227500, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1227500 {
public:
    virtual ~DeletingLeaf1227500() {}
};
static_assert(sizeof(DeletingLeaf1227500) == 8, "minimal virtual interface size");
