// Source exposure: binary-analysis; no external implementation source reused.
// Static17b3490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b3490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b3490*);
    virtual void release(Static17b3490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b3490*);
struct Static17b3490 {
    void* value;
    Static17b3490();
    ~Static17b3490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
