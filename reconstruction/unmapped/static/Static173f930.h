// Source exposure: binary-analysis; no external implementation source reused.
// Static173f930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f930*);
    virtual void release(Static173f930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f930*);
struct Static173f930 {
    void* value;
    Static173f930();
    ~Static173f930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
