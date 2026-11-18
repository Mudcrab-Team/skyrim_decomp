// Source exposure: binary-analysis; no external implementation source reused.
// Static173c170, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c170;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c170*);
    virtual void release(Static173c170*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c170*);
struct Static173c170 {
    void* value;
    Static173c170();
    ~Static173c170() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
