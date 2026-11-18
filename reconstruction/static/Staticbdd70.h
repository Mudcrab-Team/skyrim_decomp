// Source exposure: binary-analysis
// Staticbdd70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbdd70;
extern void construct(Staticbdd70*, const Descriptor*);
extern void destroy(Staticbdd70*);
struct Staticbdd70 {
    void* value;
    Staticbdd70() { construct(this, &descriptor); }
    ~Staticbdd70() { destroy(this); }
};
