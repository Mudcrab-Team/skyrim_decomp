// Source exposure: binary-analysis; no external implementation source reused.
// Static1766970, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766970;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766970*);
    virtual void release(Static1766970*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766970*);
struct Static1766970 {
    void* value;
    Static1766970();
    ~Static1766970() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
