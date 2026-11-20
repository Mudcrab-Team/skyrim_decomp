// Source exposure: binary-analysis; no external implementation source reused.
// Static1794c50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1794c50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1794c50*);
    virtual void release(Static1794c50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1794c50*);
struct Static1794c50 {
    void* value;
    Static1794c50();
    ~Static1794c50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
