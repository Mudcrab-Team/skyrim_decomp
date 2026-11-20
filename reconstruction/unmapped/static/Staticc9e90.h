// Source exposure: binary-analysis
// Staticc9e90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc9e90;
extern void construct(Staticc9e90*, const Descriptor*);
extern void destroy(Staticc9e90*);
struct Staticc9e90 {
    void* value;
    Staticc9e90() { construct(this, &descriptor); }
    ~Staticc9e90() { destroy(this); }
};
