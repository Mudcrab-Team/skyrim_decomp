// Source exposure: binary-analysis; no external implementation source reused.
// Static179c070, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c070;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c070*);
    virtual void release(Static179c070*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c070*);
struct Static179c070 {
    void* value;
    Static179c070();
    ~Static179c070() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
