// Source exposure: binary-analysis; no external implementation source reused.
// Static176e440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e440*);
    virtual void release(Static176e440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e440*);
struct Static176e440 {
    void* value;
    Static176e440();
    ~Static176e440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
