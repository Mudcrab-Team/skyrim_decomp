// Source exposure: binary-analysis
// Staticca430, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca430;
extern void construct(Staticca430*, const Descriptor*);
extern void destroy(Staticca430*);
struct Staticca430 {
    void* value;
    Staticca430() { construct(this, &descriptor); }
    ~Staticca430() { destroy(this); }
};
