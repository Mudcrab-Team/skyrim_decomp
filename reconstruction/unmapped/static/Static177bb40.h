// Source exposure: binary-analysis; no external implementation source reused.
// Static177bb40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177bb40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177bb40*);
    virtual void release(Static177bb40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177bb40*);
struct Static177bb40 {
    void* value;
    Static177bb40();
    ~Static177bb40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
