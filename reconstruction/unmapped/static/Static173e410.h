// Source exposure: binary-analysis; no external implementation source reused.
// Static173e410, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e410;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e410*);
    virtual void release(Static173e410*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e410*);
struct Static173e410 {
    void* value;
    Static173e410();
    ~Static173e410() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
