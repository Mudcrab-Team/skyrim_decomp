// Source exposure: binary-analysis
// DeletingLeaf146610, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf146610 {
public:
    virtual ~DeletingLeaf146610() {}
};
static_assert(sizeof(DeletingLeaf146610) == 8, "minimal virtual interface size");
