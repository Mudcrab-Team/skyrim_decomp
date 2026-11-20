// Source exposure: binary-analysis; no external implementation source reused.
// Static179f670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f670*);
    virtual void release(Static179f670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f670*);
struct Static179f670 {
    void* value;
    Static179f670();
    ~Static179f670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
