// TESRegionDataWeather, TESRegionData, WeatherType, WeatherList, DataHeader: GUESS(low)
// dataHeader, flags, unk09, priority, unk0B, unk0C, weatherTypes, cur, next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Inferred names: GUESS(low)
// Origin: original body and public prefix adapted from CommonLibSSE-NG, MIT.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
// TESRegionDataWeather, TESRegionData, WeatherType, WeatherList, DataHeader: GUESS(low)
// dataHeader, flags, unk09, priority, unk0B, unk0C, weatherTypes, cur, next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
struct WeatherType;
struct WeatherList { ~WeatherList(); WeatherType* cur; WeatherList* next; };
struct DataHeader { std::uint8_t flags, unk09, priority, unk0B; std::uint32_t unk0C; };
class TESRegionData { public: virtual ~TESRegionData(); DataHeader dataHeader; };
class TESRegionDataWeather : public TESRegionData { public: ~TESRegionDataWeather() override; WeatherList weatherTypes; };
