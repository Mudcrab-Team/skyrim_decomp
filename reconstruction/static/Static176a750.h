// Source exposure: binary-analysis; no external implementation source reused.
// Static176a750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a750*);
    virtual void release(Static176a750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a750*);
struct Static176a750 {
    void* value;
    Static176a750();
    ~Static176a750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
