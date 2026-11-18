// Source exposure: binary-analysis
// Static21640, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21640;
extern void construct(Static21640*, const Descriptor*);
extern void destroy(Static21640*);
struct Static21640 {
    void* value;
    Static21640() { construct(this, &descriptor); }
    ~Static21640() { destroy(this); }
};
