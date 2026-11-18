// Source exposure: binary-analysis; no external implementation source reused.
// Static176b060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b060*);
    virtual void release(Static176b060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b060*);
struct Static176b060 {
    void* value;
    Static176b060();
    ~Static176b060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
