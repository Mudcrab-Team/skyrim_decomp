// Source exposure: binary-analysis; no external implementation source reused.
// Static17b1260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b1260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b1260*);
    virtual void release(Static17b1260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b1260*);
struct Static17b1260 {
    void* value;
    Static17b1260();
    ~Static17b1260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
