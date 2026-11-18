// Source exposure: binary-analysis; no external implementation source reused.
// Static176a930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a930*);
    virtual void release(Static176a930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a930*);
struct Static176a930 {
    void* value;
    Static176a930();
    ~Static176a930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
