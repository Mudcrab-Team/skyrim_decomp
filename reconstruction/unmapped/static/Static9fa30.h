// Source exposure: binary-analysis
// Static9fa30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9fa30;
extern void construct(Static9fa30*, const Descriptor*);
extern void destroy(Static9fa30*);
struct Static9fa30 {
    void* value;
    Static9fa30() { construct(this, &descriptor); }
    ~Static9fa30() { destroy(this); }
};
