// Source exposure: binary-analysis; no external implementation source reused.
// Static176fc50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176fc50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176fc50*);
    virtual void release(Static176fc50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176fc50*);
struct Static176fc50 {
    void* value;
    Static176fc50();
    ~Static176fc50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
