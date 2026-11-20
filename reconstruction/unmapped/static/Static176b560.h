// Source exposure: binary-analysis; no external implementation source reused.
// Static176b560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b560*);
    virtual void release(Static176b560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b560*);
struct Static176b560 {
    void* value;
    Static176b560();
    ~Static176b560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
