// Source exposure: binary-analysis
// Staticc5510, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc5510;
extern void construct(Staticc5510*, const Descriptor*);
extern void destroy(Staticc5510*);
struct Staticc5510 {
    void* value;
    Staticc5510() { construct(this, &descriptor); }
    ~Staticc5510() { destroy(this); }
};
