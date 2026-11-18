// Source exposure: binary-analysis
// Static93140, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static93140;
extern void construct(Static93140*, const Descriptor*);
extern void destroy(Static93140*);
struct Static93140 {
    void* value;
    Static93140() { construct(this, &descriptor); }
    ~Static93140() { destroy(this); }
};
