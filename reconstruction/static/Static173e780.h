// Source exposure: binary-analysis; no external implementation source reused.
// Static173e780, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e780;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e780*);
    virtual void release(Static173e780*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e780*);
struct Static173e780 {
    void* value;
    Static173e780();
    ~Static173e780() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
