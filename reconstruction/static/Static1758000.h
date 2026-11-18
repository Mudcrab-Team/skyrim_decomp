// Source exposure: binary-analysis; no external implementation source reused.
// Static1758000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758000*);
    virtual void release(Static1758000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758000*);
struct Static1758000 {
    void* value;
    Static1758000();
    ~Static1758000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
