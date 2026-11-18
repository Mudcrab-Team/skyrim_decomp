// Source exposure: binary-analysis
// Static101350, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101350;
extern void construct(Static101350*, const Descriptor*);
extern void destroy(Static101350*);
struct Static101350 {
    void* value;
    Static101350() { construct(this, &descriptor); }
    ~Static101350() { destroy(this); }
};
