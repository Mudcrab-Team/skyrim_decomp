// Source exposure: binary-analysis; no external implementation source reused.
// Static176fd40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176fd40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176fd40*);
    virtual void release(Static176fd40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176fd40*);
struct Static176fd40 {
    void* value;
    Static176fd40();
    ~Static176fd40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
