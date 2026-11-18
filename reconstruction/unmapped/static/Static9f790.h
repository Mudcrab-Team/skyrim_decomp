// Source exposure: binary-analysis
// Static9f790, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f790;
extern void construct(Static9f790*, const Descriptor*);
extern void destroy(Static9f790*);
struct Static9f790 {
    void* value;
    Static9f790() { construct(this, &descriptor); }
    ~Static9f790() { destroy(this); }
};
