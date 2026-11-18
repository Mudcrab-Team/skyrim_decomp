// Source exposure: binary-analysis
// Static24500, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24500;
extern void construct(Static24500*, const Descriptor*);
extern void destroy(Static24500*);
struct Static24500 {
    void* value;
    Static24500() { construct(this, &descriptor); }
    ~Static24500() { destroy(this); }
};
