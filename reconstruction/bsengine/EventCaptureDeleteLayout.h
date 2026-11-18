// Source exposure: mixed (community declarations and local binary analysis).
// Code origin: interface and reference-count declarations adapted from the pinned public headers; derived scalar declarations originally inferred from target member accesses. No implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT), include/RE/B/BSTEvent.h and BSIntrusiveRefCounted.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// EventCaptureDeleteLayout: GUESS(medium) STANDIN; public fieldless event interface alias.
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
// EventCaptureDeleteLayout: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout { public: virtual ~EventCaptureDeleteLayout(); };
static_assert(sizeof(EventCaptureDeleteLayout)==8, "represented event interface");
// EventCapture5e82b0: GUESS(low) STANDIN; observed capture representation.
class EventCapture5e82b0 : public EventCaptureDeleteLayout { public: ~EventCapture5e82b0() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
};
static_assert(sizeof(EventCapture5e82b0)==16, "represented captures");
static_assert(offsetof(EventCapture5e82b0,capture08)==8, "observed capture offset");
// EventCaptureDeleteLayout1: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout1 { public: virtual ~EventCaptureDeleteLayout1(); };
static_assert(sizeof(EventCaptureDeleteLayout1)==8, "represented event interface");
// EventCapture66d180: GUESS(low) STANDIN; observed capture representation.
class EventCapture66d180 : public EventCaptureDeleteLayout1 { public: ~EventCapture66d180() override;
// capture08: GUESS(low); observed 1-byte access at 0x8
std::uint8_t capture08;
};
static_assert(sizeof(EventCapture66d180)==16, "represented captures");
static_assert(offsetof(EventCapture66d180,capture08)==8, "observed capture offset");
// EventCaptureDeleteLayout2: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout2 { public: virtual ~EventCaptureDeleteLayout2(); };
static_assert(sizeof(EventCaptureDeleteLayout2)==8, "represented event interface");
// EventCapture66e400: GUESS(low) STANDIN; observed capture representation.
class EventCapture66e400 : public EventCaptureDeleteLayout2 { public: ~EventCapture66e400() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66e400)==24, "represented captures");
static_assert(offsetof(EventCapture66e400,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66e400,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout3: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout3 { public: virtual ~EventCaptureDeleteLayout3(); };
static_assert(sizeof(EventCaptureDeleteLayout3)==8, "represented event interface");
// EventCapture66e480: GUESS(low) STANDIN; observed capture representation.
class EventCapture66e480 : public EventCaptureDeleteLayout3 { public: ~EventCapture66e480() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66e480)==24, "represented captures");
static_assert(offsetof(EventCapture66e480,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66e480,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout4: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout4 { public: virtual ~EventCaptureDeleteLayout4(); };
static_assert(sizeof(EventCaptureDeleteLayout4)==8, "represented event interface");
// EventCapture66e500: GUESS(low) STANDIN; observed capture representation.
class EventCapture66e500 : public EventCaptureDeleteLayout4 { public: ~EventCapture66e500() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66e500)==24, "represented captures");
static_assert(offsetof(EventCapture66e500,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66e500,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout5: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout5 { public: virtual ~EventCaptureDeleteLayout5(); };
static_assert(sizeof(EventCaptureDeleteLayout5)==8, "represented event interface");
// EventCapture66e580: GUESS(low) STANDIN; observed capture representation.
class EventCapture66e580 : public EventCaptureDeleteLayout5 { public: ~EventCapture66e580() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66e580)==24, "represented captures");
static_assert(offsetof(EventCapture66e580,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66e580,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout6: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout6 { public: virtual ~EventCaptureDeleteLayout6(); };
static_assert(sizeof(EventCaptureDeleteLayout6)==8, "represented event interface");
// EventCapture66e600: GUESS(low) STANDIN; observed capture representation.
class EventCapture66e600 : public EventCaptureDeleteLayout6 { public: ~EventCapture66e600() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66e600)==24, "represented captures");
static_assert(offsetof(EventCapture66e600,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66e600,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout7: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout7 { public: virtual ~EventCaptureDeleteLayout7(); };
static_assert(sizeof(EventCaptureDeleteLayout7)==8, "represented event interface");
// EventCapture66e680: GUESS(low) STANDIN; observed capture representation.
class EventCapture66e680 : public EventCaptureDeleteLayout7 { public: ~EventCapture66e680() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66e680)==24, "represented captures");
static_assert(offsetof(EventCapture66e680,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66e680,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout8: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout8 { public: virtual ~EventCaptureDeleteLayout8(); };
static_assert(sizeof(EventCaptureDeleteLayout8)==8, "represented event interface");
// EventCapture66e700: GUESS(low) STANDIN; observed capture representation.
class EventCapture66e700 : public EventCaptureDeleteLayout8 { public: ~EventCapture66e700() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66e700)==24, "represented captures");
static_assert(offsetof(EventCapture66e700,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66e700,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout9: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout9 { public: virtual ~EventCaptureDeleteLayout9(); };
static_assert(sizeof(EventCaptureDeleteLayout9)==8, "represented event interface");
// EventCapture66e780: GUESS(low) STANDIN; observed capture representation.
class EventCapture66e780 : public EventCaptureDeleteLayout9 { public: ~EventCapture66e780() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66e780)==24, "represented captures");
static_assert(offsetof(EventCapture66e780,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66e780,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout10: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout10 { public: virtual ~EventCaptureDeleteLayout10(); };
static_assert(sizeof(EventCaptureDeleteLayout10)==8, "represented event interface");
// EventCapture66e800: GUESS(low) STANDIN; observed capture representation.
class EventCapture66e800 : public EventCaptureDeleteLayout10 { public: ~EventCapture66e800() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66e800)==24, "represented captures");
static_assert(offsetof(EventCapture66e800,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66e800,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout11: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout11 { public: virtual ~EventCaptureDeleteLayout11(); };
static_assert(sizeof(EventCaptureDeleteLayout11)==8, "represented event interface");
// EventCapture66e880: GUESS(low) STANDIN; observed capture representation.
class EventCapture66e880 : public EventCaptureDeleteLayout11 { public: ~EventCapture66e880() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66e880)==24, "represented captures");
static_assert(offsetof(EventCapture66e880,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66e880,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout12: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout12 { public: virtual ~EventCaptureDeleteLayout12(); };
static_assert(sizeof(EventCaptureDeleteLayout12)==8, "represented event interface");
// EventCapture66e900: GUESS(low) STANDIN; observed capture representation.
class EventCapture66e900 : public EventCaptureDeleteLayout12 { public: ~EventCapture66e900() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66e900)==24, "represented captures");
static_assert(offsetof(EventCapture66e900,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66e900,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout13: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout13 { public: virtual ~EventCaptureDeleteLayout13(); };
static_assert(sizeof(EventCaptureDeleteLayout13)==8, "represented event interface");
// EventCapture66e980: GUESS(low) STANDIN; observed capture representation.
class EventCapture66e980 : public EventCaptureDeleteLayout13 { public: ~EventCapture66e980() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66e980)==24, "represented captures");
static_assert(offsetof(EventCapture66e980,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66e980,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout14: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout14 { public: virtual ~EventCaptureDeleteLayout14(); };
static_assert(sizeof(EventCaptureDeleteLayout14)==8, "represented event interface");
// EventCapture66ea00: GUESS(low) STANDIN; observed capture representation.
class EventCapture66ea00 : public EventCaptureDeleteLayout14 { public: ~EventCapture66ea00() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66ea00)==24, "represented captures");
static_assert(offsetof(EventCapture66ea00,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66ea00,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout15: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout15 { public: virtual ~EventCaptureDeleteLayout15(); };
static_assert(sizeof(EventCaptureDeleteLayout15)==8, "represented event interface");
// EventCapture66ea80: GUESS(low) STANDIN; observed capture representation.
class EventCapture66ea80 : public EventCaptureDeleteLayout15 { public: ~EventCapture66ea80() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66ea80)==24, "represented captures");
static_assert(offsetof(EventCapture66ea80,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66ea80,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout16: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout16 { public: virtual ~EventCaptureDeleteLayout16(); };
static_assert(sizeof(EventCaptureDeleteLayout16)==8, "represented event interface");
// EventCapture66eb00: GUESS(low) STANDIN; observed capture representation.
class EventCapture66eb00 : public EventCaptureDeleteLayout16 { public: ~EventCapture66eb00() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66eb00)==24, "represented captures");
static_assert(offsetof(EventCapture66eb00,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66eb00,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout17: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout17 { public: virtual ~EventCaptureDeleteLayout17(); };
static_assert(sizeof(EventCaptureDeleteLayout17)==8, "represented event interface");
// EventCapture66eb80: GUESS(low) STANDIN; observed capture representation.
class EventCapture66eb80 : public EventCaptureDeleteLayout17 { public: ~EventCapture66eb80() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66eb80)==24, "represented captures");
static_assert(offsetof(EventCapture66eb80,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66eb80,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout18: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout18 { public: virtual ~EventCaptureDeleteLayout18(); };
static_assert(sizeof(EventCaptureDeleteLayout18)==8, "represented event interface");
// EventCapture66ec00: GUESS(low) STANDIN; observed capture representation.
class EventCapture66ec00 : public EventCaptureDeleteLayout18 { public: ~EventCapture66ec00() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66ec00)==24, "represented captures");
static_assert(offsetof(EventCapture66ec00,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66ec00,capture10)==16, "observed capture offset");
// EventCaptureDeleteLayout19: GUESS(medium) STANDIN; fieldless public event-sink interface alias.
class EventCaptureDeleteLayout19 { public: virtual ~EventCaptureDeleteLayout19(); };
static_assert(sizeof(EventCaptureDeleteLayout19)==8, "represented event interface");
// EventCapture66ec80: GUESS(low) STANDIN; observed capture representation.
class EventCapture66ec80 : public EventCaptureDeleteLayout19 { public: ~EventCapture66ec80() override;
// capture08: GUESS(low); observed 8-byte access at 0x8
std::uint64_t capture08;
// capture10: GUESS(low); observed 1-byte access at 0x10
std::uint8_t capture10;
};
static_assert(sizeof(EventCapture66ec80)==24, "represented captures");
static_assert(offsetof(EventCapture66ec80,capture08)==8, "observed capture offset");
static_assert(offsetof(EventCapture66ec80,capture10)==16, "observed capture offset");
}
