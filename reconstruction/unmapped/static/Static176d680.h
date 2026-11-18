// Source exposure: binary-analysis; no external implementation source reused.
// Static176d680, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d680;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d680*);
    virtual void release(Static176d680*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d680*);
struct Static176d680 {
    void* value;
    Static176d680();
    ~Static176d680() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
