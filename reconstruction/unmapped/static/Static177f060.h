// Source exposure: binary-analysis; no external implementation source reused.
// Static177f060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f060*);
    virtual void release(Static177f060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f060*);
struct Static177f060 {
    void* value;
    Static177f060();
    ~Static177f060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
