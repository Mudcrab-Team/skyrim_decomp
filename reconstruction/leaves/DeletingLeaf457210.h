// Source exposure: binary-analysis
// DeletingLeaf457210, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457210 {
public:
    virtual ~DeletingLeaf457210() {}
};
static_assert(sizeof(DeletingLeaf457210) == 8, "minimal virtual interface size");
