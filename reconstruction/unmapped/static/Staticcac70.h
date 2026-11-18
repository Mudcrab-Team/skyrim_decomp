// Source exposure: binary-analysis
// Staticcac70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcac70;
extern void construct(Staticcac70*, const Descriptor*);
extern void destroy(Staticcac70*);
struct Staticcac70 {
    void* value;
    Staticcac70() { construct(this, &descriptor); }
    ~Staticcac70() { destroy(this); }
};
