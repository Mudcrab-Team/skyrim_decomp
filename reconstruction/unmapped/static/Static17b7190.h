// Source exposure: binary-analysis
// Static17b7190, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17b7190;
extern void construct(Static17b7190*);
struct Static17b7190 {
    Static17b7190() { construct(this); }
    ~Static17b7190() {}
};
