// Source exposure: binary-analysis; no external implementation source reused.
// Static1772400, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772400;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772400*);
    virtual void release(Static1772400*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772400*);
struct Static1772400 {
    void* value;
    Static1772400();
    ~Static1772400() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
