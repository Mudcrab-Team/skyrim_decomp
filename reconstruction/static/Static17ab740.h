// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab740*);
    virtual void release(Static17ab740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab740*);
struct Static17ab740 {
    void* value;
    Static17ab740();
    ~Static17ab740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
