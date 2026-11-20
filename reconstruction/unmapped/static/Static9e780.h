// Source exposure: binary-analysis
// Static9e780, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9e780;
extern void construct(Static9e780*, const Descriptor*);
extern void destroy(Static9e780*);
struct Static9e780 {
    void* value;
    Static9e780() { construct(this, &descriptor); }
    ~Static9e780() { destroy(this); }
};
