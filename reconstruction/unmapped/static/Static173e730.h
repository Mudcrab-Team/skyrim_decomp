// Source exposure: binary-analysis; no external implementation source reused.
// Static173e730, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e730;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e730*);
    virtual void release(Static173e730*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e730*);
struct Static173e730 {
    void* value;
    Static173e730();
    ~Static173e730() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
