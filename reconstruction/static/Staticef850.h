// Source exposure: binary-analysis
// Staticef850, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef850;
extern void construct(Staticef850*, const Descriptor*);
extern void destroy(Staticef850*);
struct Staticef850 {
    void* value;
    Staticef850() { construct(this, &descriptor); }
    ~Staticef850() { destroy(this); }
};
