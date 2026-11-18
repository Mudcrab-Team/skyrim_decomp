// Source exposure: binary-analysis; no external implementation source reused.
// Static177c360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c360*);
    virtual void release(Static177c360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c360*);
struct Static177c360 {
    void* value;
    Static177c360();
    ~Static177c360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
