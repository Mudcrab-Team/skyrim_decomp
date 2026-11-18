// Source exposure: binary-analysis; no external implementation source reused.
// Static177bf00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177bf00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177bf00*);
    virtual void release(Static177bf00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177bf00*);
struct Static177bf00 {
    void* value;
    Static177bf00();
    ~Static177bf00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
