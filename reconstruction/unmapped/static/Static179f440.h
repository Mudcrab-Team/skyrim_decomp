// Source exposure: binary-analysis; no external implementation source reused.
// Static179f440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f440*);
    virtual void release(Static179f440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f440*);
struct Static179f440 {
    void* value;
    Static179f440();
    ~Static179f440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
