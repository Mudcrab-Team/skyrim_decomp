// Source exposure: binary-analysis; no external implementation source reused.
// Static174bc50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174bc50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174bc50*);
    virtual void release(Static174bc50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174bc50*);
struct Static174bc50 {
    void* value;
    Static174bc50();
    ~Static174bc50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
