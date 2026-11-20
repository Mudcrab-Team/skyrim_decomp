// Source exposure: binary-analysis; no external implementation source reused.
// Static175e810, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e810;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e810*);
    virtual void release(Static175e810*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e810*);
struct Static175e810 {
    void* value;
    Static175e810();
    ~Static175e810() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
