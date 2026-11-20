// Source exposure: binary-analysis; no external implementation source reused.
// Static179c390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c390*);
    virtual void release(Static179c390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c390*);
struct Static179c390 {
    void* value;
    Static179c390();
    ~Static179c390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
