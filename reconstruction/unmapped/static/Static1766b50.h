// Source exposure: binary-analysis; no external implementation source reused.
// Static1766b50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766b50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766b50*);
    virtual void release(Static1766b50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766b50*);
struct Static1766b50 {
    void* value;
    Static1766b50();
    ~Static1766b50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
