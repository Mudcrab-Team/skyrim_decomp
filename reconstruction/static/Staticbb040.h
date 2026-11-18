// Source exposure: binary-analysis
// Staticbb040, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbb040;
extern void construct(Staticbb040*, const Descriptor*);
extern void destroy(Staticbb040*);
struct Staticbb040 {
    void* value;
    Staticbb040() { construct(this, &descriptor); }
    ~Staticbb040() { destroy(this); }
};
