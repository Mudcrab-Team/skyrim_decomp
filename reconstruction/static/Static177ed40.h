// Source exposure: binary-analysis; no external implementation source reused.
// Static177ed40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ed40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ed40*);
    virtual void release(Static177ed40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ed40*);
struct Static177ed40 {
    void* value;
    Static177ed40();
    ~Static177ed40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
