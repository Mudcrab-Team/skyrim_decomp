// Source exposure: binary-analysis
// Staticef760, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef760;
extern void construct(Staticef760*, const Descriptor*);
extern void destroy(Staticef760*);
struct Staticef760 {
    void* value;
    Staticef760() { construct(this, &descriptor); }
    ~Staticef760() { destroy(this); }
};
