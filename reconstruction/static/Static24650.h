// Source exposure: binary-analysis
// Static24650, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24650;
extern void construct(Static24650*, const Descriptor*);
extern void destroy(Static24650*);
struct Static24650 {
    void* value;
    Static24650() { construct(this, &descriptor); }
    ~Static24650() { destroy(this); }
};
