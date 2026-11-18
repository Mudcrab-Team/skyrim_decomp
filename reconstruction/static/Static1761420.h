// Source exposure: binary-analysis; no external implementation source reused.
// Static1761420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761420*);
    virtual void release(Static1761420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761420*);
struct Static1761420 {
    void* value;
    Static1761420();
    ~Static1761420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
