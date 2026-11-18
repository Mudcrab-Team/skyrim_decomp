// Source exposure: binary-analysis
// Staticef520, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef520;
extern void construct(Staticef520*, const Descriptor*);
extern void destroy(Staticef520*);
struct Staticef520 {
    void* value;
    Staticef520() { construct(this, &descriptor); }
    ~Staticef520() { destroy(this); }
};
