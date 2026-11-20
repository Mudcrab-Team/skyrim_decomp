// Source exposure: binary-analysis; no external implementation source reused.
// Static1752240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752240*);
    virtual void release(Static1752240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752240*);
struct Static1752240 {
    void* value;
    Static1752240();
    ~Static1752240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
