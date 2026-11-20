// Source exposure: binary-analysis; no external implementation source reused.
// Static17b6230, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b6230;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b6230*);
    virtual void release(Static17b6230*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b6230*);
struct Static17b6230 {
    void* value;
    Static17b6230();
    ~Static17b6230() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
