// Source exposure: binary-analysis
// Static24200, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24200;
extern void construct(Static24200*, const Descriptor*);
extern void destroy(Static24200*);
struct Static24200 {
    void* value;
    Static24200() { construct(this, &descriptor); }
    ~Static24200() { destroy(this); }
};
