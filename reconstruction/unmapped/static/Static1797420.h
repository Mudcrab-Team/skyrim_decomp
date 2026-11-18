// Source exposure: binary-analysis; no external implementation source reused.
// Static1797420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1797420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1797420*);
    virtual void release(Static1797420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1797420*);
struct Static1797420 {
    void* value;
    Static1797420();
    ~Static1797420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
