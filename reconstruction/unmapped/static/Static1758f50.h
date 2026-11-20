// Source exposure: binary-analysis; no external implementation source reused.
// Static1758f50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758f50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758f50*);
    virtual void release(Static1758f50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758f50*);
struct Static1758f50 {
    void* value;
    Static1758f50();
    ~Static1758f50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
