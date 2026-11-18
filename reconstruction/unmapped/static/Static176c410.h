// Source exposure: binary-analysis; no external implementation source reused.
// Static176c410, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c410;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c410*);
    virtual void release(Static176c410*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c410*);
struct Static176c410 {
    void* value;
    Static176c410();
    ~Static176c410() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
