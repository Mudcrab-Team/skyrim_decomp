// Source exposure: binary-analysis; no external implementation source reused.
// Static177ed90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ed90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ed90*);
    virtual void release(Static177ed90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ed90*);
struct Static177ed90 {
    void* value;
    Static177ed90();
    ~Static177ed90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
