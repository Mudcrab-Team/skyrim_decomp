// Source exposure: binary-analysis
// Staticcaa40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcaa40;
extern void construct(Staticcaa40*, const Descriptor*);
extern void destroy(Staticcaa40*);
struct Staticcaa40 {
    void* value;
    Staticcaa40() { construct(this, &descriptor); }
    ~Staticcaa40() { destroy(this); }
};
