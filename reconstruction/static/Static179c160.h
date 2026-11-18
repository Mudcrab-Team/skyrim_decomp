// Source exposure: binary-analysis; no external implementation source reused.
// Static179c160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c160*);
    virtual void release(Static179c160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c160*);
struct Static179c160 {
    void* value;
    Static179c160();
    ~Static179c160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
