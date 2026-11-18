// Source exposure: binary-analysis; no external implementation source reused.
// Static177ba50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ba50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ba50*);
    virtual void release(Static177ba50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ba50*);
struct Static177ba50 {
    void* value;
    Static177ba50();
    ~Static177ba50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
