// Source exposure: binary-analysis; no external implementation source reused.
// Static177ab00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ab00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ab00*);
    virtual void release(Static177ab00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ab00*);
struct Static177ab00 {
    void* value;
    Static177ab00();
    ~Static177ab00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
