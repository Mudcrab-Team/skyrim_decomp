// Source exposure: binary-analysis
// Staticbdd40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbdd40;
extern void construct(Staticbdd40*, const Descriptor*);
extern void destroy(Staticbdd40*);
struct Staticbdd40 {
    void* value;
    Staticbdd40() { construct(this, &descriptor); }
    ~Staticbdd40() { destroy(this); }
};
