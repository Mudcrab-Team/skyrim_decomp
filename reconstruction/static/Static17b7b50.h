// Source exposure: binary-analysis; no external implementation source reused.
// Static17b7b50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b7b50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b7b50*);
    virtual void release(Static17b7b50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b7b50*);
struct Static17b7b50 {
    void* value;
    Static17b7b50();
    ~Static17b7b50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
