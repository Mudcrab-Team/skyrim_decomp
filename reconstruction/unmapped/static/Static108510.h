// Source exposure: binary-analysis
// Static108510, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108510;
extern void construct(Static108510*, const Descriptor*);
extern void destroy(Static108510*);
struct Static108510 {
    void* value;
    Static108510() { construct(this, &descriptor); }
    ~Static108510() { destroy(this); }
};
