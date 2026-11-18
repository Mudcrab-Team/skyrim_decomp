// Source exposure: binary-analysis; no external implementation source reused.
// Static173d650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d650*);
    virtual void release(Static173d650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d650*);
struct Static173d650 {
    void* value;
    Static173d650();
    ~Static173d650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
