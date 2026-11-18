// Source exposure: binary-analysis; no external implementation source reused.
// Static179f260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f260*);
    virtual void release(Static179f260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f260*);
struct Static179f260 {
    void* value;
    Static179f260();
    ~Static179f260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
