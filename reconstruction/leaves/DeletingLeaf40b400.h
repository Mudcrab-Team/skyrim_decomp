// Source exposure: binary-analysis
// DeletingLeaf40b400, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf40b400 {
public:
    virtual ~DeletingLeaf40b400() {}
};
static_assert(sizeof(DeletingLeaf40b400) == 8, "minimal virtual interface size");
