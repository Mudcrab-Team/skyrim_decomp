// Source exposure: binary-analysis
// Staticef430, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef430;
extern void construct(Staticef430*, const Descriptor*);
extern void destroy(Staticef430*);
struct Staticef430 {
    void* value;
    Staticef430() { construct(this, &descriptor); }
    ~Staticef430() { destroy(this); }
};
