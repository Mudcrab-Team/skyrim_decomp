// Source exposure: binary-analysis; no external implementation source reused.
// Static1769f80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769f80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769f80*);
    virtual void release(Static1769f80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769f80*);
struct Static1769f80 {
    void* value;
    Static1769f80();
    ~Static1769f80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
