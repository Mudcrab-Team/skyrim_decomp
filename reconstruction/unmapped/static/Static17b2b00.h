// Source exposure: binary-analysis
// Static17b2b00, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17b2b00;
extern void construct(Static17b2b00*);
struct Static17b2b00 {
    Static17b2b00() { construct(this); }
    ~Static17b2b00() {}
};
