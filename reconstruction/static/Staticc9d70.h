// Source exposure: binary-analysis
// Staticc9d70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc9d70;
extern void construct(Staticc9d70*, const Descriptor*);
extern void destroy(Staticc9d70*);
struct Staticc9d70 {
    void* value;
    Staticc9d70() { construct(this, &descriptor); }
    ~Staticc9d70() { destroy(this); }
};
