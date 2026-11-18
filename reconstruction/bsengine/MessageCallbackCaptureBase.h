// Source exposure: mixed (public base declarations and local member-access analysis).
// Code origin: base declarations adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; derived declarations originally inferred from local field accesses. No implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Layout aliases and capture fields: GUESS(low) STANDIN; observed access widths and offsets constrain scalar representations, not original field boundaries or semantic types.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
struct MessageCaptureRefCount { volatile std::uint32_t referenceCount; };
// MessageCallbackCaptureBase: GUESS(medium) STANDIN; public base declaration adapted as an incomplete method set.
class MessageCallbackCaptureBase : public MessageCaptureRefCount {
public:
    virtual ~MessageCallbackCaptureBase();
    std::uint32_t unknown0C;
};
static_assert(sizeof(MessageCallbackCaptureBase) == 16, "represented base");
// CaptureLayout575ba0: GUESS(low) STANDIN; independent owner binding and per-field access evidence retained privately.
class CaptureLayout575ba0 : public MessageCallbackCaptureBase {
public:
    ~CaptureLayout575ba0() override;
    // capture10: GUESS(low); observed 8-byte access at offset 0x10
    std::uint64_t capture10;
};
static_assert(sizeof(CaptureLayout575ba0) == 24, "represented captures");
static_assert(offsetof(CaptureLayout575ba0, capture10) == 16, "observed member offset");
// CaptureLayout57dff0: GUESS(low) STANDIN; independent owner binding and per-field access evidence retained privately.
class CaptureLayout57dff0 : public MessageCallbackCaptureBase {
public:
    ~CaptureLayout57dff0() override;
    // capture10: GUESS(low); observed 4-byte access at offset 0x10
    std::uint32_t capture10;
};
static_assert(sizeof(CaptureLayout57dff0) == 24, "represented captures");
static_assert(offsetof(CaptureLayout57dff0, capture10) == 16, "observed member offset");
// CaptureLayout5824b0: GUESS(low) STANDIN; independent owner binding and per-field access evidence retained privately.
class CaptureLayout5824b0 : public MessageCallbackCaptureBase {
public:
    ~CaptureLayout5824b0() override;
};
static_assert(sizeof(CaptureLayout5824b0) == 16, "represented captures");
// CaptureLayout94ae80: GUESS(low) STANDIN; independent owner binding and per-field access evidence retained privately.
class CaptureLayout94ae80 : public MessageCallbackCaptureBase {
public:
    ~CaptureLayout94ae80() override;
    // capture10: GUESS(low); observed 8-byte access at offset 0x10
    std::uint64_t capture10;
    // capture18: GUESS(low); observed 4-byte access at offset 0x18
    std::uint32_t capture18;
};
static_assert(sizeof(CaptureLayout94ae80) == 32, "represented captures");
static_assert(offsetof(CaptureLayout94ae80, capture10) == 16, "observed member offset");
static_assert(offsetof(CaptureLayout94ae80, capture18) == 24, "observed member offset");
// CaptureLayout956770: GUESS(low) STANDIN; independent owner binding and per-field access evidence retained privately.
class CaptureLayout956770 : public MessageCallbackCaptureBase {
public:
    ~CaptureLayout956770() override;
    // capture10: GUESS(low); observed 8-byte access at offset 0x10
    std::uint64_t capture10;
};
static_assert(sizeof(CaptureLayout956770) == 24, "represented captures");
static_assert(offsetof(CaptureLayout956770, capture10) == 16, "observed member offset");
// CaptureLayout95e3d0: GUESS(low) STANDIN; independent owner binding and per-field access evidence retained privately.
class CaptureLayout95e3d0 : public MessageCallbackCaptureBase {
public:
    ~CaptureLayout95e3d0() override;
};
static_assert(sizeof(CaptureLayout95e3d0) == 16, "represented captures");
// CaptureLayout95e760: GUESS(low) STANDIN; independent owner binding and per-field access evidence retained privately.
class CaptureLayout95e760 : public MessageCallbackCaptureBase {
public:
    ~CaptureLayout95e760() override;
};
static_assert(sizeof(CaptureLayout95e760) == 16, "represented captures");
// CaptureLayout964230: GUESS(low) STANDIN; independent owner binding and per-field access evidence retained privately.
class CaptureLayout964230 : public MessageCallbackCaptureBase {
public:
    ~CaptureLayout964230() override;
    // capture10: GUESS(low); observed 8-byte access at offset 0x10
    std::uint64_t capture10;
};
static_assert(sizeof(CaptureLayout964230) == 24, "represented captures");
static_assert(offsetof(CaptureLayout964230, capture10) == 16, "observed member offset");
// CaptureLayout972e50: GUESS(low) STANDIN; independent owner binding and per-field access evidence retained privately.
class CaptureLayout972e50 : public MessageCallbackCaptureBase {
public:
    ~CaptureLayout972e50() override;
    // capture10: GUESS(low); observed 8-byte access at offset 0x10
    std::uint64_t capture10;
};
static_assert(sizeof(CaptureLayout972e50) == 24, "represented captures");
static_assert(offsetof(CaptureLayout972e50, capture10) == 16, "observed member offset");
// CaptureLayout972e80: GUESS(low) STANDIN; independent owner binding and per-field access evidence retained privately.
class CaptureLayout972e80 : public MessageCallbackCaptureBase {
public:
    ~CaptureLayout972e80() override;
    // capture10: GUESS(low); observed 8-byte access at offset 0x10
    std::uint64_t capture10;
};
static_assert(sizeof(CaptureLayout972e80) == 24, "represented captures");
static_assert(offsetof(CaptureLayout972e80, capture10) == 16, "observed member offset");
// CaptureLayout972eb0: GUESS(low) STANDIN; independent owner binding and per-field access evidence retained privately.
class CaptureLayout972eb0 : public MessageCallbackCaptureBase {
public:
    ~CaptureLayout972eb0() override;
    // capture10: GUESS(low); observed 8-byte access at offset 0x10
    std::uint64_t capture10;
    // capture18: GUESS(low); observed 4-byte access at offset 0x18
    std::uint32_t capture18;
    // capture1C: GUESS(low); observed 4-byte access at offset 0x1c
    std::uint32_t capture1C;
};
static_assert(sizeof(CaptureLayout972eb0) == 32, "represented captures");
static_assert(offsetof(CaptureLayout972eb0, capture10) == 16, "observed member offset");
static_assert(offsetof(CaptureLayout972eb0, capture18) == 24, "observed member offset");
static_assert(offsetof(CaptureLayout972eb0, capture1C) == 28, "observed member offset");
// CaptureLayout983730: GUESS(low) STANDIN; independent owner binding and per-field access evidence retained privately.
class CaptureLayout983730 : public MessageCallbackCaptureBase {
public:
    ~CaptureLayout983730() override;
    // capture10: GUESS(low); observed 8-byte access at offset 0x10
    std::uint64_t capture10;
    // capture18: GUESS(low); observed 1-byte access at offset 0x18
    std::uint8_t capture18;
    // capture1C: GUESS(low); observed 4-byte access at offset 0x1c
    std::uint32_t capture1C;
};
static_assert(sizeof(CaptureLayout983730) == 32, "represented captures");
static_assert(offsetof(CaptureLayout983730, capture10) == 16, "observed member offset");
static_assert(offsetof(CaptureLayout983730, capture18) == 24, "observed member offset");
static_assert(offsetof(CaptureLayout983730, capture1C) == 28, "observed member offset");
// CaptureLayout9837d0: GUESS(low) STANDIN; independent owner binding and per-field access evidence retained privately.
class CaptureLayout9837d0 : public MessageCallbackCaptureBase {
public:
    ~CaptureLayout9837d0() override;
    // capture10: GUESS(low); observed 8-byte access at offset 0x10
    std::uint64_t capture10;
};
static_assert(sizeof(CaptureLayout9837d0) == 24, "represented captures");
static_assert(offsetof(CaptureLayout9837d0, capture10) == 16, "observed member offset");
// CaptureLayout99fa20: GUESS(low) STANDIN; independent owner binding and per-field access evidence retained privately.
class CaptureLayout99fa20 : public MessageCallbackCaptureBase {
public:
    ~CaptureLayout99fa20() override;
    // capture10: GUESS(low); observed 8-byte access at offset 0x10
    std::uint64_t capture10;
    // capture18: GUESS(low); observed 4-byte access at offset 0x18
    std::uint32_t capture18;
    // capture1C: GUESS(low); observed 4-byte access at offset 0x1c
    std::uint32_t capture1C;
};
static_assert(sizeof(CaptureLayout99fa20) == 32, "represented captures");
static_assert(offsetof(CaptureLayout99fa20, capture10) == 16, "observed member offset");
static_assert(offsetof(CaptureLayout99fa20, capture18) == 24, "observed member offset");
static_assert(offsetof(CaptureLayout99fa20, capture1C) == 28, "observed member offset");
}
