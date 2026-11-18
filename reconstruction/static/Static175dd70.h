// Source exposure: binary-analysis; no external implementation source reused.
// Static175dd70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175dd70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175dd70*);
    virtual void release(Static175dd70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175dd70*);
struct Static175dd70 {
    void* value;
    Static175dd70();
    ~Static175dd70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
