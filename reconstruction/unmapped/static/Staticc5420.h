// Source exposure: binary-analysis
// Staticc5420, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc5420;
extern void construct(Staticc5420*, const Descriptor*);
extern void destroy(Staticc5420*);
struct Staticc5420 {
    void* value;
    Staticc5420() { construct(this, &descriptor); }
    ~Staticc5420() { destroy(this); }
};
