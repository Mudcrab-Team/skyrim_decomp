// Source exposure: binary-analysis
// Static24110, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24110;
extern void construct(Static24110*, const Descriptor*);
extern void destroy(Static24110*);
struct Static24110 {
    void* value;
    Static24110() { construct(this, &descriptor); }
    ~Static24110() { destroy(this); }
};
