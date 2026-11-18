// Source exposure: binary-analysis
// Staticef580, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef580;
extern void construct(Staticef580*, const Descriptor*);
extern void destroy(Staticef580*);
struct Staticef580 {
    void* value;
    Staticef580() { construct(this, &descriptor); }
    ~Staticef580() { destroy(this); }
};
