// Source exposure: binary-analysis
// Static9f910, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f910;
extern void construct(Static9f910*, const Descriptor*);
extern void destroy(Static9f910*);
struct Static9f910 {
    void* value;
    Static9f910() { construct(this, &descriptor); }
    ~Static9f910() { destroy(this); }
};
