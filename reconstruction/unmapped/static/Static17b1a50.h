// Source exposure: binary-analysis
// Static17b1a50, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17b1a50;
extern void construct(Static17b1a50*);
struct Static17b1a50 {
    Static17b1a50() { construct(this); }
    ~Static17b1a50() {}
};
