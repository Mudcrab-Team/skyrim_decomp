// Source exposure: binary-analysis
// Staticb6860, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6860;
extern void construct(Staticb6860*, const Descriptor*);
extern void destroy(Staticb6860*);
struct Staticb6860 {
    void* value;
    Staticb6860() { construct(this, &descriptor); }
    ~Staticb6860() { destroy(this); }
};
