// Source exposure: binary-analysis; no external implementation source reused.
// Static173e370, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e370;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e370*);
    virtual void release(Static173e370*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e370*);
struct Static173e370 {
    void* value;
    Static173e370();
    ~Static173e370() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
