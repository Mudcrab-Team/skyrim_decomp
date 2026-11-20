// Source exposure: binary-analysis
// Staticefc40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefc40;
extern void construct(Staticefc40*, const Descriptor*);
extern void destroy(Staticefc40*);
struct Staticefc40 {
    void* value;
    Staticefc40() { construct(this, &descriptor); }
    ~Staticefc40() { destroy(this); }
};
