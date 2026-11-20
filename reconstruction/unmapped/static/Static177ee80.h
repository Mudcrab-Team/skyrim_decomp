// Source exposure: binary-analysis; no external implementation source reused.
// Static177ee80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ee80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ee80*);
    virtual void release(Static177ee80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ee80*);
struct Static177ee80 {
    void* value;
    Static177ee80();
    ~Static177ee80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
