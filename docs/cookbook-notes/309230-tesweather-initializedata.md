# 0x309230 TESWeather::InitializeData

<!-- tags: method/diagnostic -->

- Function: 0x309230 TESWeather::InitializeData
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: loop-shape
- Best score: 477/477 (aligned_matching_bytes)
- Attempts: 4

## What differed

Field initialization order and the array initialization loops passed the local compare only with this statement order, `std::memset` for the zero-filled and fixed-byte buffers, and explicit indexed loops for the alpha table and the default colour rows.

## Spellings tried that did not help

- Combining separate color array loops or re-ordering adjacent zero-fills changed instruction order.

## Spelling that fixed it

```cpp
for (std::uint32_t i = 0; i < kTotalLayers; ++i)
{
    cloudAlpha[i][ColorTimes::kSunrise] = 1.0f;
    cloudAlpha[i][ColorTimes::kDay] = 1.0f;
    cloudAlpha[i][ColorTimes::kSunset] = 1.0f;
    cloudAlpha[i][ColorTimes::kNight] = 1.0f;
}
std::memset(imageSpaces, 0, sizeof(imageSpaces));
```
