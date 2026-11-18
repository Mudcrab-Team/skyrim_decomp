// Source exposure: binary-analysis
// Static9ed20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ed20;
extern void construct(Static9ed20*, const Descriptor*);
extern void destroy(Static9ed20*);
struct Static9ed20 {
    void* value;
    Static9ed20() { construct(this, &descriptor); }
    ~Static9ed20() { destroy(this); }
};
