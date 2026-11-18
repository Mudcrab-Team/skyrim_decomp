// Source exposure: binary-analysis; no external implementation source reused.
// Static17c3520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c3520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c3520*);
    virtual void release(Static17c3520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c3520*);
struct Static17c3520 {
    void* value;
    Static17c3520();
    ~Static17c3520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
