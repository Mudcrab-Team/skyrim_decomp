// Source exposure: binary-analysis; no external implementation source reused.
// Static1769d50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769d50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769d50*);
    virtual void release(Static1769d50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769d50*);
struct Static1769d50 {
    void* value;
    Static1769d50();
    ~Static1769d50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
