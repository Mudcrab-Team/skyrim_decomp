// Source exposure: binary-analysis; no external implementation source reused.
// Static177b730, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b730;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b730*);
    virtual void release(Static177b730*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b730*);
struct Static177b730 {
    void* value;
    Static177b730();
    ~Static177b730() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
