// Source exposure: binary-analysis
// Staticcabc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcabc0;
extern void construct(Staticcabc0*, const Descriptor*);
extern void destroy(Staticcabc0*);
struct Staticcabc0 {
    void* value;
    Staticcabc0() { construct(this, &descriptor); }
    ~Staticcabc0() { destroy(this); }
};
