// Source exposure: binary-analysis; no external implementation source reused.
// Static17b0730, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b0730;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b0730*);
    virtual void release(Static17b0730*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b0730*);
struct Static17b0730 {
    void* value;
    Static17b0730();
    ~Static17b0730() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
