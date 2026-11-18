// Source exposure: binary-analysis; no external implementation source reused.
// Static174df70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174df70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174df70*);
    virtual void release(Static174df70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174df70*);
struct Static174df70 {
    void* value;
    Static174df70();
    ~Static174df70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
