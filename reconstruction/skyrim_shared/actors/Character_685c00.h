// Character, Point3, x, y, z, Value, Compute, Function685c00, Function68ab20, PrecacheData, Lookup, Apply, Start, Continue, Finish: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).

#pragma once
// Character, Point3, x, y, z, Value, Compute, Function685c00, Function68ab20, PrecacheData, Lookup, Apply, Start, Continue, Finish: GUESS(low)
struct Point3 { float x, y, z; };
class Value { public: void Apply(void*); };
class Character {
public:
    float Compute(float);
    Value* Lookup();
    void Start();
    void Continue();
    void Finish(int, int);
    bool Function685c00(Point3*, void*, float);
    void Function68ab20(void*);
    void PrecacheData();
};
