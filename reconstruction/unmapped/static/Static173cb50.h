// Source exposure: binary-analysis; no external implementation source reused.
// Static173cb50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173cb50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173cb50*);
    virtual void release(Static173cb50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173cb50*);
struct Static173cb50 {
    void* value;
    Static173cb50();
    ~Static173cb50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
