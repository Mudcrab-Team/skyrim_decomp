// Source exposure: binary-analysis; no external implementation source reused.
// Static177ba00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ba00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ba00*);
    virtual void release(Static177ba00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ba00*);
struct Static177ba00 {
    void* value;
    Static177ba00();
    ~Static177ba00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
