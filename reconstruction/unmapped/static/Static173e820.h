// Source exposure: binary-analysis; no external implementation source reused.
// Static173e820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e820*);
    virtual void release(Static173e820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e820*);
struct Static173e820 {
    void* value;
    Static173e820();
    ~Static173e820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
