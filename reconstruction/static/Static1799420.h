// Source exposure: binary-analysis; no external implementation source reused.
// Static1799420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1799420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1799420*);
    virtual void release(Static1799420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1799420*);
struct Static1799420 {
    void* value;
    Static1799420();
    ~Static1799420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
