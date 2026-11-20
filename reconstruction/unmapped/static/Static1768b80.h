// Source exposure: binary-analysis; no external implementation source reused.
// Static1768b80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768b80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768b80*);
    virtual void release(Static1768b80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768b80*);
struct Static1768b80 {
    void* value;
    Static1768b80();
    ~Static1768b80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
