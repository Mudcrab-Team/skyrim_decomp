// Source exposure: binary-analysis
// Static109c50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109c50;
extern void construct(Static109c50*, const Descriptor*);
extern void destroy(Static109c50*);
struct Static109c50 {
    void* value;
    Static109c50() { construct(this, &descriptor); }
    ~Static109c50() { destroy(this); }
};
