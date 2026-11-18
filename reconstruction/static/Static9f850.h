// Source exposure: binary-analysis
// Static9f850, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f850;
extern void construct(Static9f850*, const Descriptor*);
extern void destroy(Static9f850*);
struct Static9f850 {
    void* value;
    Static9f850() { construct(this, &descriptor); }
    ~Static9f850() { destroy(this); }
};
