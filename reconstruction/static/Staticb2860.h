// Source exposure: binary-analysis
// Staticb2860, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb2860;
extern void construct(Staticb2860*, const Descriptor*);
extern void destroy(Staticb2860*);
struct Staticb2860 {
    void* value;
    Staticb2860() { construct(this, &descriptor); }
    ~Staticb2860() { destroy(this); }
};
