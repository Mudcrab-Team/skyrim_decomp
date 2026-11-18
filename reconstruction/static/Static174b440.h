// Source exposure: binary-analysis; no external implementation source reused.
// Static174b440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174b440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174b440*);
    virtual void release(Static174b440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174b440*);
struct Static174b440 {
    void* value;
    Static174b440();
    ~Static174b440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
