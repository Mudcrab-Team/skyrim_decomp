// Source exposure: binary-analysis; no external implementation source reused.
// Static179f620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f620*);
    virtual void release(Static179f620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f620*);
struct Static179f620 {
    void* value;
    Static179f620();
    ~Static179f620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
