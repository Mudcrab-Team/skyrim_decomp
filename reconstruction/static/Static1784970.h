// Source exposure: binary-analysis; no external implementation source reused.
// Static1784970, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784970;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784970*);
    virtual void release(Static1784970*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784970*);
struct Static1784970 {
    void* value;
    Static1784970();
    ~Static1784970() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
