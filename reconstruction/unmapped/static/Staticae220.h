// Source exposure: binary-analysis
// Staticae220, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticae220;
extern void construct(Staticae220*, const Descriptor*);
extern void destroy(Staticae220*);
struct Staticae220 {
    void* value;
    Staticae220() { construct(this, &descriptor); }
    ~Staticae220() { destroy(this); }
};
