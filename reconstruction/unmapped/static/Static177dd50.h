// Source exposure: binary-analysis; no external implementation source reused.
// Static177dd50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177dd50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177dd50*);
    virtual void release(Static177dd50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177dd50*);
struct Static177dd50 {
    void* value;
    Static177dd50();
    ~Static177dd50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
