// Source exposure: binary-analysis; no external implementation source reused.
// Static179be90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179be90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179be90*);
    virtual void release(Static179be90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179be90*);
struct Static179be90 {
    void* value;
    Static179be90();
    ~Static179be90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
