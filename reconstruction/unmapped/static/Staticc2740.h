// Source exposure: binary-analysis
// Staticc2740, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc2740;
extern void construct(Staticc2740*, const Descriptor*);
extern void destroy(Staticc2740*);
struct Staticc2740 {
    void* value;
    Staticc2740() { construct(this, &descriptor); }
    ~Staticc2740() { destroy(this); }
};
