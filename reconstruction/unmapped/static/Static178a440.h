// Source exposure: binary-analysis; no external implementation source reused.
// Static178a440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a440*);
    virtual void release(Static178a440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a440*);
struct Static178a440 {
    void* value;
    Static178a440();
    ~Static178a440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
