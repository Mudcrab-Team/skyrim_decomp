// Source exposure: binary-analysis
// Staticc9b30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc9b30;
extern void construct(Staticc9b30*, const Descriptor*);
extern void destroy(Staticc9b30*);
struct Staticc9b30 {
    void* value;
    Staticc9b30() { construct(this, &descriptor); }
    ~Staticc9b30() { destroy(this); }
};
