// Source exposure: binary-analysis
// Staticc5660, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc5660;
extern void construct(Staticc5660*, const Descriptor*);
extern void destroy(Staticc5660*);
struct Staticc5660 {
    void* value;
    Staticc5660() { construct(this, &descriptor); }
    ~Staticc5660() { destroy(this); }
};
