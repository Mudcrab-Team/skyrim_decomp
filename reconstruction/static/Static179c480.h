// Source exposure: binary-analysis; no external implementation source reused.
// Static179c480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c480*);
    virtual void release(Static179c480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c480*);
struct Static179c480 {
    void* value;
    Static179c480();
    ~Static179c480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
