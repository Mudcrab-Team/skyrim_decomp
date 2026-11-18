// Source exposure: binary-analysis
// Staticc2620, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc2620;
extern void construct(Staticc2620*, const Descriptor*);
extern void destroy(Staticc2620*);
struct Staticc2620 {
    void* value;
    Staticc2620() { construct(this, &descriptor); }
    ~Staticc2620() { destroy(this); }
};
