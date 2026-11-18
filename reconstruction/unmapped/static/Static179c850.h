// Source exposure: binary-analysis; no external implementation source reused.
// Static179c850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c850*);
    virtual void release(Static179c850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c850*);
struct Static179c850 {
    void* value;
    Static179c850();
    ~Static179c850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
