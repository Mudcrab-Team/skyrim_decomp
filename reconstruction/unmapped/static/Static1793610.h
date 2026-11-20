// Source exposure: binary-analysis
// Static1793610, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static1793610;
extern void construct(Static1793610*);
struct Static1793610 {
    Static1793610() { construct(this); }
    ~Static1793610() {}
};
