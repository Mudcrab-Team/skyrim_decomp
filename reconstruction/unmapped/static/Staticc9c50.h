// Source exposure: binary-analysis
// Staticc9c50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc9c50;
extern void construct(Staticc9c50*, const Descriptor*);
extern void destroy(Staticc9c50*);
struct Staticc9c50 {
    void* value;
    Staticc9c50() { construct(this, &descriptor); }
    ~Staticc9c50() { destroy(this); }
};
