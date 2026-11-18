// Source exposure: binary-analysis; no external implementation source reused.
// Static174dd70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174dd70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174dd70*);
    virtual void release(Static174dd70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174dd70*);
struct Static174dd70 {
    void* value;
    Static174dd70();
    ~Static174dd70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
