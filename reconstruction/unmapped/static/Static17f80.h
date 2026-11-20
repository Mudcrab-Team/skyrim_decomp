// Source exposure: binary-analysis
// Static17f80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static17f80;
extern void construct(Static17f80*, const Descriptor*);
extern void destroy(Static17f80*);
struct Static17f80 {
    void* value;
    Static17f80() { construct(this, &descriptor); }
    ~Static17f80() { destroy(this); }
};
