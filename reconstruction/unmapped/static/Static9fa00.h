// Source exposure: binary-analysis
// Static9fa00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9fa00;
extern void construct(Static9fa00*, const Descriptor*);
extern void destroy(Static9fa00*);
struct Static9fa00 {
    void* value;
    Static9fa00() { construct(this, &descriptor); }
    ~Static9fa00() { destroy(this); }
};
