// Source exposure: binary-analysis
// DeletingLeafdc0210, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafdc0210 {
public:
    virtual ~DeletingLeafdc0210() {}
};
static_assert(sizeof(DeletingLeafdc0210) == 8, "minimal virtual interface size");
