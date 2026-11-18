// Source exposure: binary-analysis; no external implementation source reused.
// Static177bf50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177bf50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177bf50*);
    virtual void release(Static177bf50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177bf50*);
struct Static177bf50 {
    void* value;
    Static177bf50();
    ~Static177bf50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
