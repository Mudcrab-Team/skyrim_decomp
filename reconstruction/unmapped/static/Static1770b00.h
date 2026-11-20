// Source exposure: binary-analysis; no external implementation source reused.
// Static1770b00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770b00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770b00*);
    virtual void release(Static1770b00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770b00*);
struct Static1770b00 {
    void* value;
    Static1770b00();
    ~Static1770b00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
