// Source exposure: binary-analysis
// Static87510, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static87510;
extern void construct(Static87510*, const Descriptor*);
extern void destroy(Static87510*);
struct Static87510 {
    void* value;
    Static87510() { construct(this, &descriptor); }
    ~Static87510() { destroy(this); }
};
