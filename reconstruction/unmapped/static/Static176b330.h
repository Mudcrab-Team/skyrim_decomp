// Source exposure: binary-analysis; no external implementation source reused.
// Static176b330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b330*);
    virtual void release(Static176b330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b330*);
struct Static176b330 {
    void* value;
    Static176b330();
    ~Static176b330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
