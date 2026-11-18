// Source exposure: binary-analysis; no external implementation source reused.
// Static1741b00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741b00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741b00*);
    virtual void release(Static1741b00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741b00*);
struct Static1741b00 {
    void* value;
    Static1741b00();
    ~Static1741b00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
