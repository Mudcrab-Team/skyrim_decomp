// Source exposure: binary-analysis; no external implementation source reused.
// Static1771f50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771f50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771f50*);
    virtual void release(Static1771f50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771f50*);
struct Static1771f50 {
    void* value;
    Static1771f50();
    ~Static1771f50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
