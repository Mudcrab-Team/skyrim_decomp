// Source exposure: binary-analysis; no external implementation source reused.
// Static173db50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173db50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173db50*);
    virtual void release(Static173db50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173db50*);
struct Static173db50 {
    void* value;
    Static173db50();
    ~Static173db50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
