// Source exposure: binary-analysis; no external implementation source reused.
// Static173e230, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e230;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e230*);
    virtual void release(Static173e230*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e230*);
struct Static173e230 {
    void* value;
    Static173e230();
    ~Static173e230() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
