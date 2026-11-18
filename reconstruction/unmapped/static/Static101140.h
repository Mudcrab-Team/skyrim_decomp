// Source exposure: binary-analysis
// Static101140, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101140;
extern void construct(Static101140*, const Descriptor*);
extern void destroy(Static101140*);
struct Static101140 {
    void* value;
    Static101140() { construct(this, &descriptor); }
    ~Static101140() { destroy(this); }
};
