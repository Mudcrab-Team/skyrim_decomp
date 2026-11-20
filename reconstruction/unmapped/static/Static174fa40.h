// Source exposure: binary-analysis; no external implementation source reused.
// Static174fa40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174fa40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174fa40*);
    virtual void release(Static174fa40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174fa40*);
struct Static174fa40 {
    void* value;
    Static174fa40();
    ~Static174fa40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
