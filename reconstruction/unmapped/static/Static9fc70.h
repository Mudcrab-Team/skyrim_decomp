// Source exposure: binary-analysis
// Static9fc70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9fc70;
extern void construct(Static9fc70*, const Descriptor*);
extern void destroy(Static9fc70*);
struct Static9fc70 {
    void* value;
    Static9fc70() { construct(this, &descriptor); }
    ~Static9fc70() { destroy(this); }
};
