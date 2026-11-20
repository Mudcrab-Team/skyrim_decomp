// Source exposure: binary-analysis; no external implementation source reused.
// Static1743420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743420*);
    virtual void release(Static1743420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743420*);
struct Static1743420 {
    void* value;
    Static1743420();
    ~Static1743420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
