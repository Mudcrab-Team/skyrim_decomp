// Source exposure: binary-analysis
// Staticbb480, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbb480;
extern void construct(Staticbb480*, const Descriptor*);
extern void destroy(Staticbb480*);
struct Staticbb480 {
    void* value;
    Staticbb480() { construct(this, &descriptor); }
    ~Staticbb480() { destroy(this); }
};
