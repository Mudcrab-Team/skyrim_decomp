// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab9c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab9c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab9c0*);
    virtual void release(Static17ab9c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab9c0*);
struct Static17ab9c0 {
    void* value;
    Static17ab9c0();
    ~Static17ab9c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
