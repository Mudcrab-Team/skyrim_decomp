// Source exposure: binary-analysis
// Static14c80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static14c80;
extern void construct(Static14c80*, const Descriptor*);
extern void destroy(Static14c80*);
struct Static14c80 {
    void* value;
    Static14c80() { construct(this, &descriptor); }
    ~Static14c80() { destroy(this); }
};
