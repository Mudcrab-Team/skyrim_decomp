// Source exposure: binary-analysis; no external implementation source reused.
// Static176e760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e760*);
    virtual void release(Static176e760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e760*);
struct Static176e760 {
    void* value;
    Static176e760();
    ~Static176e760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
