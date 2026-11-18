// Source exposure: binary-analysis; no external implementation source reused.
// Static1741970, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741970;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741970*);
    virtual void release(Static1741970*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741970*);
struct Static1741970 {
    void* value;
    Static1741970();
    ~Static1741970() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
