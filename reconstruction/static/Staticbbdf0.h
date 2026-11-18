// Source exposure: binary-analysis
// Staticbbdf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbbdf0;
extern void construct(Staticbbdf0*, const Descriptor*);
extern void destroy(Staticbbdf0*);
struct Staticbbdf0 {
    void* value;
    Staticbbdf0() { construct(this, &descriptor); }
    ~Staticbbdf0() { destroy(this); }
};
