// Source exposure: binary-analysis; no external implementation source reused.
// Static176a200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a200*);
    virtual void release(Static176a200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a200*);
struct Static176a200 {
    void* value;
    Static176a200();
    ~Static176a200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
