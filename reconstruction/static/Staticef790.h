// Source exposure: binary-analysis
// Staticef790, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef790;
extern void construct(Staticef790*, const Descriptor*);
extern void destroy(Staticef790*);
struct Staticef790 {
    void* value;
    Staticef790() { construct(this, &descriptor); }
    ~Staticef790() { destroy(this); }
};
