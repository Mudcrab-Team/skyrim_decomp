// Source exposure: binary-analysis
// Static9e810, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9e810;
extern void construct(Static9e810*, const Descriptor*);
extern void destroy(Static9e810*);
struct Static9e810 {
    void* value;
    Static9e810() { construct(this, &descriptor); }
    ~Static9e810() { destroy(this); }
};
