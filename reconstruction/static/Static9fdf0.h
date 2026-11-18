// Source exposure: binary-analysis
// Static9fdf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9fdf0;
extern void construct(Static9fdf0*, const Descriptor*);
extern void destroy(Static9fdf0*);
struct Static9fdf0 {
    void* value;
    Static9fdf0() { construct(this, &descriptor); }
    ~Static9fdf0() { destroy(this); }
};
