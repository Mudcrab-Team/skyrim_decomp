// Source exposure: binary-analysis
// Static24440, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24440;
extern void construct(Static24440*, const Descriptor*);
extern void destroy(Static24440*);
struct Static24440 {
    void* value;
    Static24440() { construct(this, &descriptor); }
    ~Static24440() { destroy(this); }
};
