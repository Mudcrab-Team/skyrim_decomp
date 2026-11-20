// Source exposure: binary-analysis; no external implementation source reused.
// Static1769d00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769d00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769d00*);
    virtual void release(Static1769d00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769d00*);
struct Static1769d00 {
    void* value;
    Static1769d00();
    ~Static1769d00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
