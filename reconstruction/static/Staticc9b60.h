// Source exposure: binary-analysis
// Staticc9b60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc9b60;
extern void construct(Staticc9b60*, const Descriptor*);
extern void destroy(Staticc9b60*);
struct Staticc9b60 {
    void* value;
    Staticc9b60() { construct(this, &descriptor); }
    ~Staticc9b60() { destroy(this); }
};
