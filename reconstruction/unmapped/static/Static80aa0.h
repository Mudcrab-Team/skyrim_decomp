// Source exposure: binary-analysis
// Static80aa0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static80aa0;
extern void construct(Static80aa0*, const Descriptor*);
extern void destroy(Static80aa0*);
struct Static80aa0 {
    void* value;
    Static80aa0() { construct(this, &descriptor); }
    ~Static80aa0() { destroy(this); }
};
