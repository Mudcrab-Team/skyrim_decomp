// Source exposure: binary-analysis; no external implementation source reused.
// Static174cd80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174cd80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174cd80*);
    virtual void release(Static174cd80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174cd80*);
struct Static174cd80 {
    void* value;
    Static174cd80();
    ~Static174cd80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
