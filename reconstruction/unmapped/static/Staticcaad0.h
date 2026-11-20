// Source exposure: binary-analysis
// Staticcaad0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcaad0;
extern void construct(Staticcaad0*, const Descriptor*);
extern void destroy(Staticcaad0*);
struct Staticcaad0 {
    void* value;
    Staticcaad0() { construct(this, &descriptor); }
    ~Staticcaad0() { destroy(this); }
};
