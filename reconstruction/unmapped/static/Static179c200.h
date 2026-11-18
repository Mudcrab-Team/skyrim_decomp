// Source exposure: binary-analysis; no external implementation source reused.
// Static179c200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c200*);
    virtual void release(Static179c200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c200*);
struct Static179c200 {
    void* value;
    Static179c200();
    ~Static179c200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
