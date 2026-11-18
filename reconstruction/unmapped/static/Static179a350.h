// Source exposure: binary-analysis; no external implementation source reused.
// Static179a350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179a350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179a350*);
    virtual void release(Static179a350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179a350*);
struct Static179a350 {
    void* value;
    Static179a350();
    ~Static179a350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
