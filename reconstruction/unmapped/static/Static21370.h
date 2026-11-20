// Source exposure: binary-analysis
// Static21370, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21370;
extern void construct(Static21370*, const Descriptor*);
extern void destroy(Static21370*);
struct Static21370 {
    void* value;
    Static21370() { construct(this, &descriptor); }
    ~Static21370() { destroy(this); }
};
