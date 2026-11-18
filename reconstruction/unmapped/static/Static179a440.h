// Source exposure: binary-analysis; no external implementation source reused.
// Static179a440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179a440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179a440*);
    virtual void release(Static179a440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179a440*);
struct Static179a440 {
    void* value;
    Static179a440();
    ~Static179a440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
