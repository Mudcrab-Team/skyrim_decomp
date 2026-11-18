// Source exposure: binary-analysis
// DeletingLeafcd6410, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafcd6410 {
public:
    virtual ~DeletingLeafcd6410() {}
};
static_assert(sizeof(DeletingLeafcd6410) == 8, "minimal virtual interface size");
