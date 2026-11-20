// Source exposure: binary-analysis
// Staticef940, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef940;
extern void construct(Staticef940*, const Descriptor*);
extern void destroy(Staticef940*);
struct Staticef940 {
    void* value;
    Staticef940() { construct(this, &descriptor); }
    ~Staticef940() { destroy(this); }
};
