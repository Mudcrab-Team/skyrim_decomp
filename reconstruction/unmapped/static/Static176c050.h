// Source exposure: binary-analysis; no external implementation source reused.
// Static176c050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c050*);
    virtual void release(Static176c050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c050*);
struct Static176c050 {
    void* value;
    Static176c050();
    ~Static176c050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
