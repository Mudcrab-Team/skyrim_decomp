// Source exposure: binary-analysis
// Staticc9d10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc9d10;
extern void construct(Staticc9d10*, const Descriptor*);
extern void destroy(Staticc9d10*);
struct Staticc9d10 {
    void* value;
    Staticc9d10() { construct(this, &descriptor); }
    ~Staticc9d10() { destroy(this); }
};
