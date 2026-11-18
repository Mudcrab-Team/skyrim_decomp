// TES, Function1a5a00, Function1a5a30, FindCell, Cell, GetValueA, GetValueB, fallback: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).

#pragma once
// TES, Function1a5a00, Function1a5a30, FindCell, Cell, GetValueA, GetValueB, fallback: GUESS(low)
class Cell {
public:
    float GetValueA();
    float GetValueB();
};
class TES {
public:
    Cell* FindCell();
    float Function1a5a00();
    float Function1a5a30();
};
extern const float fallback;
