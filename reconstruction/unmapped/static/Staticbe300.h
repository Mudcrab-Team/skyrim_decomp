// Source exposure: binary-analysis
// Staticbe300, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbe300;
extern void construct(Staticbe300*, const Descriptor*);
extern void destroy(Staticbe300*);
struct Staticbe300 {
    void* value;
    Staticbe300() { construct(this, &descriptor); }
    ~Staticbe300() { destroy(this); }
};
