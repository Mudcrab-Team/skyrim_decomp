// Source exposure: binary-analysis
// Staticc6c30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc6c30;
extern void construct(Staticc6c30*, const Descriptor*);
extern void destroy(Staticc6c30*);
struct Staticc6c30 {
    void* value;
    Staticc6c30() { construct(this, &descriptor); }
    ~Staticc6c30() { destroy(this); }
};
